//! @file
#ifndef SOLVER_H
#define SOLVER_H

#include "structures_consts.h"

//! Solves linear equations within EPSILON for given coefficients
//!
//! @return The equation's root and a flag confirming a single solution (linear_eq_flg)
//! @note While working turnes on a flag indicating the equation is linear(linear_eq_flg)
solutions solve_linear_equation(const equation_params* params, solutions *res);

//! Solves equations of the form 0x = const
//!
//! @return The number of solutions: 0 or infinity
solutions solve_const_equation(const equation_params* params, solutions *res);

double discriminant(const equation_params* params);

//! Solves quadratic equations within EPSILON for given coefficients
//!
//! @return The roots of the equation and the number of solutions
//! @note While working calls the solve_linear_equation() function if the equation is linear
solutions solve_quadratic_equation(const equation_params* params);

#endif // SOLVER_h