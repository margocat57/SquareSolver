#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Для NULL
#include <assert.h>
#include <stdint.h>

#include "structures_consts.h"
#include "solver.h"
#include "work_with_file.h"
#include "comparison.h"
#include "choose_output_file.h"
#include "color_printf.h"
#include "assert.h"

void output_program_solution(const solutions* solution_program, FILE *OUTPUT){
    switch(solution_program->number_of_solutions){
        case ZERO:
            my_printf(OUTPUT, "Программа не нашла решений");
            break;
        case ONE:
            my_printf(OUTPUT, "Программа нашла решение x = %lg", solution_program->solution_x1);
            break;
        case TWO:
            my_printf(OUTPUT, "Программа нашла решения x1 = %lg  x2 = %lg",
                solution_program->solution_x1, solution_program->solution_x2);
            break;
        case INFINITE:
            my_printf(OUTPUT, "Программа нашла бесконечно решений");
            break;
        default:
            assert(false);
            break;
    }
}

void output_ideal_solution(const solutions* solution_ideal, FILE *OUTPUT){
    switch (solution_ideal->number_of_solutions){
        case ZERO:
            my_printf(OUTPUT, "хотя искомое уравнение не имеет решений");
            break;
        case ONE:
            my_printf(OUTPUT, "хотя искомое уравнение имеет решение x = %lg",
                solution_ideal -> solution_x1);
            break;
        case TWO:
            my_printf(OUTPUT, "хотя искомое уравнение имеет решения x1 = %lg x2 = %lg",
                    solution_ideal -> solution_x1, solution_ideal -> solution_x2);
            break;
        case INFINITE:
            my_printf(OUTPUT, "хотя искомое уравнение имеет бесконечно решений");
            break;
        default:
            assert(false);
            break;
    }
}

bool check_if_test_correct(const equation_params* params, const solutions* solution_ideal){
    MY_ASSERT((params == NULL), "Assertion_failed pointer params is null");
    MY_ASSERT((solution_ideal == NULL), "Assertion_failed pointer solution_ideal is null");
    solutions solution_program = solve_quadratic_equation(params);

    if (!double_is_equal(solution_program.number_of_solutions, solution_ideal->number_of_solutions)||
        !double_is_equal(solution_program.solution_x1, solution_ideal->solution_x1) || 
        !double_is_equal(solution_program.solution_x2, solution_ideal->solution_x2)) {

        output_program_solution(&solution_program, get_output_file());
        output_ideal_solution(solution_ideal, get_output_file());
        my_printf(get_output_file(), "Коэффиценты уравнения(в котором возникла ошибка) a = %lg b = %lg c = %lg", params->coef_a, params->coef_b, params->coef_c);
        return false;
    } 
    return true;
}

int count_incorrect_tests(void){
    int count_incorrect = 0;

    struct equation_params_and_solutions* tests_solve = get_tests(NAME_FILE);
    int nmb_tests = number_of_tests(NAME_FILE);

    for (int i = 0; i < nmb_tests; i++) {
        MY_ASSERT((0 <= i && i < nmb_tests), "Assertion_failed");
        count_incorrect += !check_if_test_correct(&tests_solve[i].equation_params_for_tests, 
                                        &tests_solve[i].solutions_for_tests);
    }
    free(tests_solve);
    tests_solve = NULL;

    return count_incorrect;
}
