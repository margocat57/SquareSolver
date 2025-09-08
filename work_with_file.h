//! @file
#ifndef WORK_WITH_FILE_H
#define WORK_WITH_FILE_H

#include "structures_consts.h"

//! Checks if the test file contains any tests and counts the number of tests in the file 
//!     using fgets() to count lines
int number_of_tests(const char* name_of_file);


//! Checks if the test file contains any tests and reads tests line 
//!     by line from the file into an array for tests
//!
//! @note IMPORTANT: Allocates memory for an array whose length is the number of tests 
//!     obtained using the number_of_tests() function.
//!
//! @note Uses fgets() to read data line by line into a buffer array
//! @note Then uses sscanf to parse the data element by element into the tests array
//!
//! @note The first line in the file contains variable names, so we skip parsing it
struct equation_params_and_solutions* get_tests(const char* name_of_file);

#endif // WORK_WITH_FILE_H