#include <stdio.h>
#include <locale.h>
#include <math.h>

const char* NO_SOLUTIONS_MSG = "Решений не существует";

typedef struct education_params{
    double coef_a;
    double coef_b;
    double coef_c;
} EDUCATION_PARAMS;

typedef struct solutions{
    double solution_x1;
    double solution_x2;
    const char *msg;
} SOLUTIONS;

SOLUTIONS solve(const EDUCATION_PARAMS* params) {
    SOLUTIONS res = {0, 0, NULL};

    if (params->coef_a == 0) {
        if (params->coef_b == 0) {
            if (params->coef_c == 0) {
                res.msg = "Бесконечное количество решений";
            } else {
                res.msg = NO_SOLUTIONS_MSG;
            }
        } else {
            res.solution_x1 = (-params->coef_c) / params->coef_b;
            res.solution_x2 = res.solution_x1;
        }
    }
    else {
        double discriminant = params->coef_b * params->coef_b - 4 * params->coef_a * params->coef_c;

        if (discriminant < 0) {
            res.msg = NO_SOLUTIONS_MSG;
        }
        else if (discriminant == 0) {
            res.solution_x1 = (-params->coef_b) / (2 * params->coef_a);
            res.solution_x2 = res.solution_x1;
        }
        else {
            double sqrt_d = sqrt(discriminant);
            res.solution_x1 = (-params->coef_b + sqrt_d) / (2 * params->coef_a);
            res.solution_x2 = (-params->coef_b - sqrt_d) / (2 * params->coef_a);
        }
    }

    return res;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void run_quadratic_equation_solver() {
    EDUCATION_PARAMS params = {0, 0, 0};
    
    printf("Введите коэффициенты a, b, c уравнения ax^2 + bx + c через пробел: ");
    
    if (scanf("%lf %lf %lf", &params.coef_a, &params.coef_b, &params.coef_c) != 3) {
        printf("Ошибка ввода! Пожалуйста, введите три числа.\n");
        clear_input_buffer(); 
        return;
    }
    
    clear_input_buffer();
    
    SOLUTIONS solution = solve(&params);
    
    if (solution.msg != NULL) {
        printf("%s\n", solution.msg);
    }
    else if (solution.solution_x1 == solution.solution_x2) {
        printf("Решение уравнения: %.2f\n", solution.solution_x1);
    }
    else {
        printf("Решения уравнения: %.2f и %.2f\n", 
            solution.solution_x1, solution.solution_x2);
    }
}

int main(void) {
    setlocale(LC_ALL, "rus");
    int contin_flg;

    do{
    clear_input_buffer();
    run_quadratic_equation_solver();

    printf("Если хотите решить еще одно уравнение, введите любую цифру\n");
    }while(scanf("%d", &contin_flg) == 1);


    return 0;
}