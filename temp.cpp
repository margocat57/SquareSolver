#include <stdio.h>
#include <stdlib.h> // Для NULL

#include "file_for_define.h"

// этот файл нужен для отладки чтения данных из файла
struct equation_params{
    double coef_a;
    double coef_b;
    double coef_c;
    const char *msg_error_input;
    int flg_exit;
};

struct solutions{
    double solution_x1;
    double solution_x2;
    int number_of_solutions;
    int linear_eq_flg;
};

struct equation_params_and_solutions{
    struct equation_params equation_params_for_tests;
    struct solutions solutions_for_tests;
};

int main() {
    struct equation_params_and_solutions TESTS_solve[10] = {};
    FILE *file_ptr;
    char buffer[255]; 
    const char *filename = "tests_for_solver.txt"; 

    file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        perror(RED(Ошибка открытия файла));
        return 1;
    }

    if (fgets(buffer, sizeof(buffer), file_ptr) == NULL) {
        fclose(file_ptr);
        return 1;
    }

    int i = 0;
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        sscanf(buffer, "%lg %lg %lg %lg %lg %d %d", &TESTS_solve[i].equation_params_for_tests.coef_a, 
            &TESTS_solve[i].equation_params_for_tests.coef_b, 
            &TESTS_solve[i].equation_params_for_tests.coef_c, 
            &TESTS_solve[i].solutions_for_tests.solution_x1,
            &TESTS_solve[i].solutions_for_tests.solution_x2,
            &TESTS_solve[i].solutions_for_tests.number_of_solutions,
            &TESTS_solve[i].solutions_for_tests.linear_eq_flg);
            i++;
    }

    for(int i = 0; i < 10; i++){
        printf("a = %lg, b = %lg, c = %lg\n", TESTS_solve[i].equation_params_for_tests.coef_a, 
            TESTS_solve[i].equation_params_for_tests.coef_b, 
            TESTS_solve[i].equation_params_for_tests.coef_c);
        printf("x1 = %lg, x2 = %lg\n", TESTS_solve[i].solutions_for_tests.solution_x1, 
            TESTS_solve[i].solutions_for_tests.solution_x2);
    }

    fclose(file_ptr);

    return 0;
}
