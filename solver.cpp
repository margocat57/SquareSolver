#include <math.h>
#include "structures_consts.h"

int comparison(double coef){
    return coef > 0 - eps && coef < 0 + eps;
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

solutions solve_linear_equation(const equation_params* params, solutions *res) {

    if (comparison(params->coef_b)) {
        return solve_const_equation(params, res);
    } 
    res -> number_of_solutions = 1;
    res -> solution_x1 = (-params->coef_c) / params->coef_b;
    res -> solution_x2 = res -> solution_x1;

    return *res;
}


double discriminant(const equation_params* params){
    return params->coef_b * params->coef_b - 4 * params->coef_a * params->coef_c;
}


solutions solve_quadratic_equation(const equation_params* params) {
    solutions res = {};

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