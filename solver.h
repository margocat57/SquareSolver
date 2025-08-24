#ifndef SOLVER_H
#define SOLVER_H

#include "structures_consts.h"

int comparison(double coef);

solutions solve_linear_equation(const equation_params* params, solutions *res);

/* рассматриваем случай, когда линейное уравнение вырождается в константу, например
0*х=3 или 0*х=0 */
solutions solve_const_equation(const equation_params* params, solutions *res);

double discriminant(const equation_params* params);

solutions solve_quadratic_equation(const equation_params* params);

#endif // SOLVER_h