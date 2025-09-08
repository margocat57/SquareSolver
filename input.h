//! @file
#ifndef INPUT_H
#define INPUT_H

#include "structures_consts.h"


//! Uses isspace() to check if there are any characters in the input buffer that do not match the input format
//! @param [in] int start_number Pointer to the beginning of the input to be checked for extra characters
//!
//! @note Helps to indicate incorrect inputs like 1 2 3sdfghjkl
bool is_rubish_in_input(int start_number, const char* input);


//! Implements user interaction for inputting equation coefficients or the termination keyword "end" 
//!     using the fgets function for input
//!
//! @note If the input does not match the format, it displays an error message to the user and 
//!     clears the buffer if more than 50 characters were entered
equation_params_input input_params(void);

//! Implements user interaction to confirm the equation input by entering any digit
//!
//! @note Clears the input buffer if the user did not confirm the equation input.
bool confirm_input(const equation_params_input* params);

#endif //INPUT_H