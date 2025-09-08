#include <stdio.h>
#include <assert.h>

#include "structures_consts.h"
#include "color_printf.h"


void print_equations(const solutions* print_solution_equation){
    switch(print_solution_equation->number_of_solutions){
        case ZERO:
            if (print_solution_equation->linear_eq) {
                fprintf(stderr, RED("Уравнение не квадратное - решений не существует"));
                break;
            }
            puts("Решений не существует\n"); 
            break;

        case ONE:
            if (print_solution_equation->linear_eq) {
                fprintf(stderr, RED("Уравнение не квадратное - решение уравнения: %lg"), print_solution_equation->solution_x1);
                break;
            }
            printf("Решение уравнения: %lg\n", print_solution_equation->solution_x1); 
            break;

        case TWO: printf("Решения уравнения: %lg и %lg\n", 
            print_solution_equation->solution_x1, print_solution_equation->solution_x2); 
            break;
        
        case INFINITE: 
            fprintf(stderr, RED("Уравнение не квадратное - бесконечное количество решений")); 
            break;

        default:
            assert(false);
    }
}

