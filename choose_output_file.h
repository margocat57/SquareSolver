//! @file
#ifndef CHOOSE_OUTPUT_FILE_H
#define CHOOSE_OUTPUT_FILE_H

#include <stdio.h>

//! This function retrieves a pointer to the file where tests should be written.
//! 
//! @return If the pointer *current_output does not point to a valid memory location (is a NULL pointer), 
//!     the function returns stderr. 
//! @return Otherwise, it returns the file referenced by the pointer.
FILE* get_output_file(void);

//! Assigns to the *current_output pointer a pointer to the file where the tests should be written
void set_output_file(FILE*);

#endif //CHOOSE_OUTPUT_FILE_H