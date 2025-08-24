#include <stdio.h>
#include <stdlib.h> // Для NULL
#include <assert.h>

#include "file_for_define.h"
#include "structures_consts.h"

int number_of_tests(void){
    FILE *fp = fopen("tests_for_solver.txt", "r");
    char buffer[255]; 
    if (fp == NULL) {
        perror(RED(Ошибка: Не удалось открыть файл));
        return 0;
    }
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        perror(RED(Отсутвуют данные для тестов));
        return 0;
    }

    int count = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        count++;
    }

    fclose(fp); 
    return count;
}

struct equation_params_and_solutions* get_tests(void){
    int nmb_tests = number_of_tests();
    struct equation_params_and_solutions* tests_solve = (struct equation_params_and_solutions*)calloc(nmb_tests, sizeof(struct equation_params_and_solutions));
    assert(tests_solve != NULL);
    if (tests_solve == NULL){
        return NULL;
    }
    FILE *file_ptr = fopen("tests_for_solver.txt", "r");
    char buffer[255];

    if (file_ptr == NULL) {
        perror(RED(Ошибка открытия файла));
    }
    //первая строка в файле содержит названия переменных, поэтому мы ее не парсим
    if (fgets(buffer, sizeof(buffer), file_ptr) == NULL) {
        fclose(file_ptr);
        perror(RED(Отсутвуют данные для тестов));
    }
    else{
        int i = 0;
        while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
            sscanf(buffer, "%lg %lg %lg %lg %lg %d %d", &tests_solve[i].equation_params_for_tests.coef_a, 
                    &tests_solve[i].equation_params_for_tests.coef_b, 
                    &tests_solve[i].equation_params_for_tests.coef_c, 
                    &tests_solve[i].solutions_for_tests.solution_x1,
                    &tests_solve[i].solutions_for_tests.solution_x2,
                    &tests_solve[i].solutions_for_tests.number_of_solutions,
                    &tests_solve[i].solutions_for_tests.linear_eq_flg);
            i++;
        }
        fclose(file_ptr);
    }
    return tests_solve;
    // дальше работаем со значением указателя

}


