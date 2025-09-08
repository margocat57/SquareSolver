#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "input.h"
#include "clear_input.h"
#include "solver.h"
#include "output.h"
#include "color_printf.h"
#include "comparison.h"
#include "flags_for_main.h"



int main(int argc, const char** argv) {
    setlocale(LC_ALL, "rus");

    puts("Мяу. Вы используете программу, которая решает квадратные уравнения");

    equation_params eq_params = {};

    handling_flags flags[] = {
        {"-h", "--help",   ARG_BOOL_TYPE,   false, NULL},
        {"-a", "--coef_a", ARG_NUMBER_TYPE, false, &eq_params.coef_a},
        {"-b", "--coef_b", ARG_NUMBER_TYPE, false, &eq_params.coef_b},
        {"-c", "--coef_c", ARG_NUMBER_TYPE, false, &eq_params.coef_c}
    };

    size_t num_of_elem = sizeof(flags) / sizeof(flags[0]);
    
    find_flags_main(flags, argc, argv, num_of_elem);

    if (flags[HELP].is_flag) {
        print_flag_help();
        return 0; 
    }

    if (flags[COEF_A].is_flag && flags[COEF_B].is_flag && flags[COEF_C].is_flag) {
        print_flags_a_b_c(&eq_params);
        return 0;
    }

    for(;;) {   
        equation_params_input params = input_params();
        if (params.is_exit) { 
            break;
        }
        else if (params.msg_error_input != NULL) {
            fprintf(stderr, RED("%s"), ERROR_INPUT);
            continue;
        }

        if (!confirm_input(&params)) {
            continue;
        }

        clear_input_buffer();

        solutions solution_equation = solve_quadratic_equation(&params.coefficents);
        print_equations(&solution_equation);
    }
    puts("COMMIT GITHUB");
    return 0;
}

// ./quadratic - если хотим запустить не отладочные файлы


