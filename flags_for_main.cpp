#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "structures_consts.h"
#include "comparison.h"
#include "solver.h"
#include "output.h"
#include "assert.h"


void find_flags_main(handling_flags* flags, int argc, const char** argv, size_t num_of_elem){
    for (size_t flg_idx = 0 ; flg_idx < num_of_elem; flg_idx++) {
        MY_ASSERT((0 <= flg_idx && flg_idx < num_of_elem), "Assertion_failed out of index");

        for (int elem_idx = 0; elem_idx < argc; elem_idx++) {
            MY_ASSERT((0 <= elem_idx && elem_idx < argc), "Assertion_failed out of index");

            if (!strcmp(argv[elem_idx], flags[flg_idx].flag_short) || !strcmp(argv[elem_idx], flags[flg_idx].flag_long)) {
                flags[flg_idx].is_flag = true;
                if (flags[flg_idx].type && elem_idx + 1 < argc) {
                    *flags[flg_idx].coef = strtod(argv[elem_idx + 1], NULL);
                }
            }
        }
    }
}

void print_flag_help(){
    puts("Используйте флаги -a coef_a -b coef_b -c coef_c(коэффиценты можно указывать в любом порядке),если не хотите использовать программу в интерактивном режиме");
    puts("COMMIT GITHUB");
}

void print_flags_a_b_c(equation_params* params){
    solutions solution_equation = solve_quadratic_equation(params);
    print_equations(&solution_equation);
    puts("COMMIT GITHUB");
}


