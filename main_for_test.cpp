#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#include "input.h"
#include "clear_input.h"
#include "solver.h"
#include "output.h"
#include "tests_for_solver.h"
#include "structures_consts.h"
#include "choose_output_file.h"
#include "color_printf.h"
#include "flags_for_tests.h"


int main(int argc, char** argv) {
    setlocale(LC_ALL, "rus");

    puts("Мяу. Вы используете программу, которая решает квадратные уравнения");

    flags_for_tests flags[]={
        {"-h", false},
        {"--help", false},
        {"--input", false},
        {"--output", false}
    };

    size_t num_of_elem = sizeof(flags) / sizeof(flags[0]);

    find_flags_test(flags, argc, argv, num_of_elem);
    if (flags[HELP].is_flag_test || flags[H].is_flag_test){
        print_flag_help_test();
        return 0;
    }

    else if (flags[INPUT].is_flag_test){
        print_flag_input();
        return 0;
    }

    else if (flags[OUTPUT].is_flag_test){
        print_flag_output();
        return 0;
    }
    my_printf(get_output_file(), "Количество неточностей в задаче %d\n", count_incorrect_tests());

    puts("COMMIT GITHUB");
    return 0;
}
// ./tests


