#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

const char* ERROR_INPUT = "Ошибка ввода! Пожалуйста, введите три числа в указанном формате.\n";
const int INFINITE_SOLUTIONS = 3;
const double eps = 1e-2;

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

solutions solve_linear_equation(const equation_params* params, solutions *res);

/* рассматриваем случай, когда линейное уравнение вырождается в константу, например
0*х=3 или 0*х=0 */
solutions solve_const_equation(const equation_params* params, solutions *res);

double discriminant(const equation_params* params);

solutions solve_quadratic_equation(const equation_params* params);

void clear_input_buffer(void);

int musor(int *start_number, const char* input);

equation_params input_params(void);

void print_linear_solutions(const solutions* print_solution_equation);

void print_quadr_solutions(const solutions* print_solution_equation);

void print_equations(const solutions* sltns);

int comparison(double coef);

int main(void) {
    setlocale(LC_ALL, "rus");

    puts("Вы используете программу, которая решает квадратные уравнения");

    for(;;) { 
        equation_params params_main = input_params();
        if(params_main.flg_exit){
            break;
        }
        else if(params_main.msg_error_input != NULL){
            fprintf(stderr, "\033[31m%s\033[0m\n", ERROR_INPUT);
            continue;
        }

        int check=0;
        printf("Ваше квадратное уравнение %lgx^2 + %lgx + %lg?\n", params_main.coef_a, params_main.coef_b, params_main.coef_c);
        puts("Введите любое число, если да");
        if(scanf("%d", &check) != 1){
            clear_input_buffer();
            continue;
        }

        clear_input_buffer();

        solutions solution_equation = solve_quadratic_equation(&params_main);
        print_equations(&solution_equation);
    }

    return 0;
}


void clear_input_buffer(void) {
    int c = 0; 
    while ((c = getchar()) != '\n' && c != EOF) {;}
}


equation_params input_params(void){
    equation_params params = {};

    puts("Введите коэффициенты a, b, c уравнения ax^2 + bx + c в любом из удобных форматов: a = 5 b = 6 c = 7 или 5 6 7");
    puts("Если хотите закончить выполнение программы введите end ");
    
    char input[50] = {0};
    fgets(input, sizeof(input), stdin);
    int start_number = 0;
    int ret_value = sscanf(input, "%lf %lf %lf %n", &params.coef_a, &params.coef_b, &params.coef_c, &start_number);

    printf("scanf returned %d" "\n", ret_value);
    printf("start number: %d" "\n", start_number);

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

int comparison(double coef){
    return coef > 0 - eps && coef < 0 + eps;
}


solutions solve_linear_equation(const equation_params* params, solutions *res) {

    if (comparison(params->coef_b)) {
        return solve_const_equation(params, res);
    } 
    res -> number_of_solutions = 1;
    res -> solution_x1 = (-params->coef_c) / params->coef_b;
    res -> solution_x2 = res -> solution_x1;

    return *res;
}


solutions solve_const_equation(const equation_params* params, solutions *res){

    if (comparison(params->coef_c)) {
        res -> number_of_solutions = INFINITE_SOLUTIONS;
    }
    else {
        res -> number_of_solutions = 0;
    }

    return *res;
}


double discriminant(const equation_params* params){
    return params->coef_b * params->coef_b - 4 * params->coef_a * params->coef_c;
}


solutions solve_quadratic_equation(const equation_params* params) {
    solutions res = {0., 0., 0};

    if (comparison(params->coef_a)) {
        res.linear_eq_flg = 1;
        return solve_linear_equation(params, &res);
    }
    
    double discriminant_of_this_eq = discriminant(params);

    if (discriminant_of_this_eq < 0 - eps) {
        res.number_of_solutions = 0;
    }
    else if (discriminant_of_this_eq > 0 - eps && discriminant_of_this_eq < 0 + eps) {
        res.number_of_solutions = 1;
        res.solution_x1 = (-params->coef_b) / (2 * params->coef_a);
        res.solution_x2 = res.solution_x1;
    }
    else {
        res.number_of_solutions = 2;
        double sqrt_d = sqrt(discriminant_of_this_eq);
        res.solution_x1 = (-params->coef_b + sqrt_d) / (2 * params->coef_a);
        res.solution_x2 = (-params->coef_b - sqrt_d) / (2 * params->coef_a);
    }

    return res;
}

void print_linear_solutions(const solutions* print_solution_equation){
    switch(print_solution_equation->number_of_solutions){
        case 0:
            fprintf(stderr, "\033[31mУравнение не квадратное - решений не существует\033[0m\n");
            break;

        case 1:
            fprintf(stderr, "\033[31mУравнение не квадратное - решение уравнения: %.2f\033[0m\n", print_solution_equation->solution_x1);
            break;

        case INFINITE_SOLUTIONS: 
                fprintf(stderr, "\033[31mУравнение не квадратное - бесконечное количество решений\033[0m\n"); 
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
