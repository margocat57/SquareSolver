#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Для NULL
#include <assert.h>

#include "structures_consts.h"
#include "solver.h"
#include "file_for_define.h"
#include "work_with_file.h"

// поделить на функции
// динамически выделять память под массив, чтобы ее возвращать
// поставить assert на free
// заменить константу на количество строк в файле

int sravn_test(double program_param, double ideal_param){
    return fabs(program_param - ideal_param)>eps;
}

int checking(double program_solution, double ideal_solution, char info_about_quantity_solutions, char info_about_linear_equation){
    if(info_about_linear_equation && sravn_test(program_solution, ideal_solution)){
        fprintf(stderr,  RED(Индикатор линейного уравнения %lg не совпадает с эталонным %lg),
        program_solution, ideal_solution);
        return 1;
    }
    if(info_about_quantity_solutions && sravn_test(program_solution, ideal_solution)){
        fprintf(stderr, RED(Количество решений %lg  не совпадает с эталонным %lg),
        program_solution, ideal_solution);
        return 1;
    }
    if (sravn_test(program_solution, ideal_solution)){
        fprintf(stderr, RED(Решение x = %lg не совпадает с эталонным x = %lg),
        program_solution, ideal_solution);
        return 1;
    }
    return 0;
}

int check_correct(const equation_params* params, const solutions* solution_ideal){
    int non_correct_flg = 0;
    char info_about_quantity_solutions = 0;
    char info_about_linear_equation = 0;
    solutions solution_program = solve_quadratic_equation(params);

    non_correct_flg += checking(solution_program.solution_x1, solution_ideal->solution_x1, 
                                info_about_quantity_solutions, info_about_linear_equation);
    non_correct_flg += checking(solution_program.solution_x2, solution_ideal->solution_x2, 
                                info_about_quantity_solutions, info_about_linear_equation);

    info_about_quantity_solutions++;
    non_correct_flg += checking((double)solution_program.number_of_solutions, (double)solution_ideal->number_of_solutions, 
                                info_about_quantity_solutions, info_about_linear_equation);

    info_about_linear_equation++;
    non_correct_flg += checking((double)solution_program.linear_eq_flg, (double)solution_ideal->linear_eq_flg, 
                                info_about_quantity_solutions, info_about_linear_equation);

    if(non_correct_flg){
        fprintf(stderr, RED(Коэффиценты уравнения(в котором возникла ошибка) a = %lg b = %lg c = %lg), params->coef_a, params->coef_b, params->coef_c);
    }

    return non_correct_flg;
}



int count_incorrect_tests(void){
    int count_incorrect = 0;

    struct equation_params_and_solutions* tests_solve = get_tests();
    int nmb_tests = number_of_tests();

    
    for(int i = 0; i < nmb_tests; i++){
        count_incorrect += check_correct(&tests_solve[i].equation_params_for_tests, 
        &tests_solve[i].solutions_for_tests);
    }
    free(tests_solve);
    tests_solve = NULL;

    return count_incorrect;
}
