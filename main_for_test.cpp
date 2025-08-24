#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>


#include "input.h"
#include "clear_input.h"
#include "solver.h"
#include "output.h"
#include "tests_for_solver.h"
#include "file_for_define.h"


int main(void) {
    setlocale(LC_ALL, "rus");

    puts("Вы используете программу, которая решает квадратные уравнения");

    printf("Количество неточностей в задаче %d\n", count_incorrect_tests());

    for(;;) { 
        equation_params params_main = input_params();
        if(params_main.flg_exit){
            break;
        }
        else if(params_main.msg_error_input != NULL){
            // fprintf(stderr, "\033[31m%s\033[0m\n", ERROR_INPUT);
            fprintf(stderr, RED(%s), ERROR_INPUT);
            continue;
        }

        int check=0;
        printf("Ваше квадратное уравнение %lgx^2 + %lgx + %lg?\n", params_main.coef_a, params_main.coef_b, params_main.coef_c);
        puts("Введите любое число, если да");
        if(scanf("%d", &check) != 1){
            clear_input_buffer();
            continue;
        }

        clear_input_buffer();

        solutions solution_equation = solve_quadratic_equation(&params_main);
        print_equations(&solution_equation);
    }
    return 0;
}
// ./tests