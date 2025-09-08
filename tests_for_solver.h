//! @file
#ifndef TESTS_FOR_SOLVER_H
#define TESTS_FOR_SOLVER_H

#include "structures_consts.h"

//! Outputs the program's solution to the equation (or a "no solutions" message) to stderr in red color.
//!
//! @ param [in] file where program's solution should be output, this is either stderr or a .txt file
//!
//! @note Asserts on incorrect number_solutions enum value
void output_program_solution(const solutions* solution_program, FILE *OUTPUT);

//! Outputs the ideal solution to the equation (or a "no solutions" message) to stderr in red color.
//!
//! @ param [in] file where ideal solution should be output, this is either stderr or a .txt file
//!
//! @note Asserts on incorrect number_solutions enum value
void output_ideal_solution(const solutions* solution_ideal, FILE *OUTPUT);


//! Compares the program's results (each root and number_of_solutions) against the expected results
//!
//! @note If errors are detected in the quadratic equation solver's output, it calls functions 
//!     to print both the program's output and the expected output
//!
//! @return False on test fail
bool check_if_test_correct(const equation_params* params, const solutions* solution_ideal);


//! Call function to run one unit-test in diferent params
//! Calls functions from work_with_file.h to get the number of tests and a pointer to the tests array
//!
//! @return Number of test where an error occurred 
//!
//! @note function uses free() to free up memory - BE CAREFUL
int count_incorrect_tests(void);

#endif // TESTS_FOR_SOLVER_H