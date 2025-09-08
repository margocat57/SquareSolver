//! @file
#ifndef OUTPUT_H
#define OUTPUT_H

#include "structures_consts.h"

//! Displays a message to the user to stdout with the equation's solutions 
//!     based on the number of solutions found using operator switch.
//!
//! @note If equation is linear - output to stderr with red color, because user 
//!     uses program that solves square equation to solve linear equation
//! @note Asserts on incorrect number_solutions enum value

void print_equations(const solutions* print_solution_equation);


#endif //OUTPUT_H