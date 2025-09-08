#include <math.h>
#include "structures_consts.h"
#include "comparison.h"


solutions solve_const_equation(const equation_params* params, solutions *res){
    MY_ASSERT((params == NULL), "Assertion_failed pointer params is null");
    MY_ASSERT((res == NULL), "Assertion_failed pointer res is null");

    if (double_is_equal(params->coef_c, 0.)) {
        res -> number_of_solutions = INFINITE;
    }
    else {
        res -> number_of_solutions = ZERO;
    }

    return *res;
}

solutions solve_linear_equation(const equation_params* params, solutions *res) {
    MY_ASSERT((params == NULL), "Assertion_failed pointer params is null");

    if (double_is_equal(params->coef_b, 0.)) {
        return solve_const_equation(params, res);
    } 
    res -> number_of_solutions = ONE;
    res -> solution_x1 = (-params->coef_c) / params->coef_b;
    res -> solution_x2 = res -> solution_x1;

    return *res;
}


double discriminant(const equation_params* params){
    return params->coef_b * params->coef_b - 4 * params->coef_a * params->coef_c;
}

//  использовать enum вместо int num_solutions - еще добавить в аутпут
solutions solve_quadratic_equation(const equation_params* params) {
    solutions res = {};
    MY_ASSERT((params == NULL), "Assertion_failed pointer params is null");

    if (double_is_equal(params->coef_a, 0.)) {
        res.linear_eq = YES;
        return solve_linear_equation(params, &res);
    }
    
    double discriminant_of_this_eq = discriminant(params);

    if (discriminant_of_this_eq < 0 - EPSILON) {
        res.number_of_solutions = ZERO;
    }
    else if (discriminant_of_this_eq > 0 - EPSILON && discriminant_of_this_eq < 0 + EPSILON) {
        res.number_of_solutions = ONE;
        res.solution_x1 = (-params->coef_b) / (2 * params->coef_a);
        res.solution_x2 = res.solution_x1;
    }
    else {
        res.number_of_solutions = TWO;
        double sqrt_d = sqrt(discriminant_of_this_eq);
        res.solution_x1 = (-params->coef_b + sqrt_d) / (2 * params->coef_a);
        res.solution_x2 = (-params->coef_b - sqrt_d) / (2 * params->coef_a);
    }

    return res;
}