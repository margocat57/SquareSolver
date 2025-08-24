#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "clear_input.h"
#include "structures_consts.h"

const char* ERROR_INPUT = "Ошибка ввода! Пожалуйста, введите три числа в указанном формате.\n";

int musor(int *start_number, const char* input){
    const char* ptr = input;
    ptr = ptr + *start_number;
    while(*ptr){
        if (!isspace(*ptr)){
            return 1;
        }
    }
    return 0;
}

equation_params input_params(void){
    equation_params params = {};

    puts("Введите коэффициенты a, b, c уравнения ax^2 + bx + c в любом из удобных форматов: a = 5 b = 6 c = 7 или 5 6 7");
    puts("Если хотите закончить выполнение программы введите end ");
    
    char input[50] = {0};
    fgets(input, sizeof(input), stdin);
    int start_number = 0;

    if(strstr(input, "end")!=NULL){
        params.flg_exit = 1;
        return params;
    }
    else if(strchr(input, '\n')==NULL){
        params.msg_error_input = ERROR_INPUT;
        clear_input_buffer();
    }
    else if (sscanf(input, "a = %lf b = %lf c = %lf %n", &params.coef_a, &params.coef_b, &params.coef_c, &start_number) == 3){
        if (musor(&start_number, input)){
            params.msg_error_input = ERROR_INPUT;
            clear_input_buffer();
        }
        return params;
    }
    else if (sscanf(input, "%lf %lf %lf %n", &params.coef_a, &params.coef_b, &params.coef_c, &start_number) == 3){
        if (musor(&start_number, input)){
            params.msg_error_input = ERROR_INPUT;
            clear_input_buffer();
        }
        return params;
    }
    else {
        params.msg_error_input = ERROR_INPUT;
    }
    return params;
}

