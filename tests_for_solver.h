#ifndef TESTS_FOR_SOLVER_H
#define TESTS_FOR_SOLVER_H

#include "structures_consts.h"

int sravn_test(double program_param, double ideal_param);

int checking(double program_solution, double ideal_solution, char info_about_quantity_solutions, char info_about_linear_equation);

int check_correct(const equation_params* params, const solutions* solution_ideal);

int count_incorrect_tests(void);

#endif // TESTS_FOR_SOLVER_H