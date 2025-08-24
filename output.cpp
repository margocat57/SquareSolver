#include <stdio.h>

#include "structures_consts.h"
#include "file_for_define.h"

void print_linear_solutions(const solutions* print_solution_equation){
    switch(print_solution_equation->number_of_solutions){
        case 0:
            fprintf(stderr, RED(Уравнение не квадратное - решений не существует));
            break;

        case 1:
            fprintf(stderr, RED(Уравнение не квадратное - решение уравнения: %lg), print_solution_equation->solution_x1);
            break;

        case INFINITE_SOLUTIONS: 
                fprintf(stderr, RED(Уравнение не квадратное - бесконечное количество решений)); 
                break;
    }
}

void print_quadr_solutions(const solutions* print_solution_equation){
    switch(print_solution_equation->number_of_solutions){
        case 0:
            puts("Решений не существует\n"); 
            break;

        case 1:
            printf("Решение уравнения: %lg\n", print_solution_equation->solution_x1); 
            break;

        case 2: printf("Решения уравнения: %lg и %lg\n", 
            print_solution_equation->solution_x1, print_solution_equation->solution_x2); 
            break;
    }
}

void print_equations(const solutions* print_solution_equation){
    if(print_solution_equation->linear_eq_flg){
        print_linear_solutions(print_solution_equation);
    }
    else{
        print_quadr_solutions(print_solution_equation);
    }
}