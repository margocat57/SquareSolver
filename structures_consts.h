#ifndef STRUCTURES_CONSTS_H
#define STRUCTURES_CONSTS_H

extern const char* ERROR_INPUT;
// если одна переменная используется в нескольких файлах, то делать как ERROR_INPUT
// extern const int INFINITE_SOLUTIONS;
const int INFINITE_SOLUTIONS = 3;
const double eps = 1e-15;
// const int number_of_tests_input = 5;
// подумать как реализовать, так как в функции ввода у нас пользователь вводить что-то с клавиатуры, 
// а мы должны передать функции  какие то идеальные параметры и посмотреть как работает функция

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

#endif //STRUCTURES_CONSTS_H