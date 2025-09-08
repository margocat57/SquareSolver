#include <stdio.h>
#include <stdlib.h> // Для NULL
#include <assert.h>

#include "color_printf.h"
#include "structures_consts.h"

int number_of_tests(const char* name_of_file){
    FILE *fp = fopen(name_of_file, "r");
    char buffer[255]; 
    if (fp == NULL) {
        perror(RED("Ошибка: Не удалось открыть файл"));
        return 0;
    }
    //первая строка в файле содержит названия переменных
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        perror(RED("Отсутвуют данные для тестов"));
        return 0;
    }

    int count = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        count++;
    }

    fclose(fp); 
    
    return count - 1;
}

struct equation_params_and_solutions* get_tests(const char* name_of_file){
    int nmb_tests = number_of_tests(NAME_FILE);

    struct equation_params_and_solutions* tests_solve =
        (struct equation_params_and_solutions*)calloc(nmb_tests, sizeof(struct equation_params_and_solutions));
    if (tests_solve == NULL){
        assert(false);
        return NULL;
    }
    
    FILE *file_ptr = fopen(name_of_file, "r");
    char buffer[255] = {'\n'};

    if (file_ptr == NULL) {
        perror(RED("Ошибка открытия файла"));
    }
    //первая строка в файле содержит названия переменных, поэтому мы ее не парсим
    if (fgets(buffer, sizeof(buffer), file_ptr) == NULL) {
        fclose(file_ptr);
        perror(RED("Отсутвуют данные для тестов"));
    }
    else {
        int i = 0;
        while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
            sscanf(buffer, "%lg %lg %lg %lg %lg %d %d", &tests_solve[i].equation_params_for_tests.coef_a, 
                    &tests_solve[i].equation_params_for_tests.coef_b, 
                    &tests_solve[i].equation_params_for_tests.coef_c, 
                    &tests_solve[i].solutions_for_tests.solution_x1,
                    &tests_solve[i].solutions_for_tests.solution_x2,
                    &tests_solve[i].solutions_for_tests.number_of_solutions,
                    &tests_solve[i].solutions_for_tests.linear_eq);
            i++;
        }
        fclose(file_ptr);
    }
    return tests_solve;
}