#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#include "structures_consts.h"
#include "color_printf.h"
#include "choose_output_file.h"
#include "tests_for_solver.h"
#include "assert.h"

void find_flags_test(flags_for_tests* flags, int argc, char** argv, size_t num_of_elem){
    for (size_t flg_idx = 0 ; flg_idx < num_of_elem; flg_idx++) {
        MY_ASSERT((0 <= flg_idx && flg_idx < num_of_elem), "Assertion_failed out of index");

        for (int elem_idx = 0; elem_idx < argc; elem_idx++) {
            MY_ASSERT((0 <= elem_idx && elem_idx < argc), "Assertion_failed out of index");

            if (!strcmp(argv[elem_idx], flags[flg_idx].flag_test)) {
                flags[flg_idx].is_flag_test = true;
            }
        }
    }
}

void print_flag_help_test(){
    puts("Используйте флаг --input для вывода тестов в консоль");
    puts("Используйте флаг --output для записи unit-тестирования в файл report.txt");
    puts("COMMIT GITHUB");
}
// для ассерта писать в чем проблема
void print_flag_input(){
    FILE *fptr = fopen(NAME_FILE, "a+");

    if (fptr == NULL) {
        perror(RED("Ошибка открытия файла")); 
    }
    else {
        puts("Введите тесты в файл в указанном ниже формате. Если хотите закончить введите end"); 
        puts("coef_a  coef_b  coef_c  x1_ideal   x2_ideal    quantity_solutions_ideal  is_equation_linear_ideal|");
        char input[300] = {0};

        while(1) {
            fgets(input, sizeof(input), stdin);
            if (strstr(input, "end") != NULL) {
                break;
            }
            fputs(input, fptr);
        }
        fclose(fptr);
        puts("COMMIT GITHUB");
    }
}

void print_flag_output(){

    char buffer[256] = {0};
    FILE *fptr = fopen("report.txt", "w");

    if (fptr == NULL) {
        perror(RED("Ошибка открытия файла")); 
    }
    else {
        set_output_file(fptr);
        my_printf(get_output_file(), "Количество неточностей в задаче %d\n", count_incorrect_tests());

        puts("Результаты тестов записаны в файл report.txt успешно");

        fclose(fptr);
    }
}
