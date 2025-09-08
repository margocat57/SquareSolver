//! @file
#ifndef FLAGS_FOR_MAIN_H
#define FLAGS_FOR_MAIN_H
#include "structures_consts.h"

//! Parses command-line arguments and updates flag states and values
//!
//! This function iterates through a provided array of  structures handling_flags,
//!     checking for matches with the command-line arguments in argv. When a match is found,
//! it marks the flag is in arg.
//! If the flag -a, -b, -c or --coef_a, --coef_b, --coef_c is found, 
//!     the function parses the next element from the command line and assigns it to the address of the corresponding coefficient
//!
//! @param[in,out] flags   Pointer to an array of handling_flags struct to be updated.
//! @param[in] num_of_elem The number of elements in flags array.
//!
//! @note The function performs a simple linear search through arguments for each flag.
//! @note Assert is used checks that index is out of range
//!
//! @warning This function does not handle duplicate flags. If a flag appears multiple times,
//!     the last occurrence in the argument list will determine the final value of coefficent.
//! @warning The function does not distinguish between short and long flags once a match is found
void find_flags_main(handling_flags* flags, int argc, const char** argv, size_t num_of_elem);


//! Prints a list of available command-line flags and describes the program's behavior 
//!     When they are used
void print_flag_help();

//! The program runs in non-interactive mode with coefficients provided after the flags
//!
//! Prints solutions of equation
void print_flags_a_b_c(equation_params* params_main_f);


#endif //FLAGS_FOR_MAIN_H