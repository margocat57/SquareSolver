#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "clear_input.h"
#include "structures_consts.h"


bool is_rubish_in_input(int start_number, const char* input){
    const char* ptr = input;
    ptr = ptr + start_number;
    while(*ptr){
        if (!isspace(*ptr)){
            return true;
        }
    }
    return false;
}

equation_params_input input_params(void){
    equation_params_input params = {};

    puts("Введите коэффициенты a, b, c уравнения ax^2 + bx + c в любом из удобных форматов: a = 5 b = 6 c = 7 или 5 6 7");
    puts("Если хотите закончить выполнение программы введите end ");
    
    char input[50] = {0};
    fgets(input, sizeof(input), stdin);
    int start_number = 0;

    if(strstr(input, "end")!=NULL){
        params.is_exit = 1;
        return params;
    }
    else if(strchr(input, '\n')==NULL){
        params.msg_error_input = ERROR_INPUT;
        clear_input_buffer();
    }
    else if (sscanf(input, "a = %lf b = %lf c = %lf %n", &params.coefficents.coef_a, &params.coefficents.coef_b, &params.coefficents.coef_c, &start_number) == 3){
        if (is_rubish_in_input(start_number, input)){
            params.msg_error_input = ERROR_INPUT;
            clear_input_buffer();
        }
        return params;
    }
    else if (sscanf(input, "%lf %lf %lf %n", &params.coefficents.coef_a, &params.coefficents.coef_b, &params.coefficents.coef_c, &start_number) == 3){
        if (is_rubish_in_input(start_number, input)){
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

bool confirm_input(const equation_params_input* params){
    int check = 0;
    printf("Ваше квадратное уравнение %lgx^2 + %lgx + %lg?\n", params->coefficents.coef_a, params->coefficents.coef_b, params->coefficents.coef_c);
    puts("Введите любое число, если да"); 
    if (scanf("%d", &check) != 1) {
        clear_input_buffer();
        return false;
    }
    return true;
}


