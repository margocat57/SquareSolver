//! @file
#ifndef FLAGS_FOR_TESTS_H
#define FLAGS_FOR_TESTS_H

//! Parses command-line arguments and updates flag states and values
//!
//! This function iterates through a provided array of  structures handling_flags,
//!     checking for matches with the command-line arguments in argv. When a match is found,
//! it marks the flag is in arg.
//!
//! @param[in,out] flags   Pointer to an array of handling_flags struct to be updated.
//! @param[in] num_of_elem The number of elements in flags array.
//!
//! @warning This function does not handle duplicate flags. If a flag appears multiple times,
//!     the last occurrence in the argument list will determine the final value of coefficent.
//! @warning The function does not distinguish between short and long flags once a match is found
void find_flags_test(flags_for_tests* flags, int argc, char** argv, size_t num_of_elem);

//! Prints a list of available command-line flags and describes the program's behavior 
//!     When they are used
void print_flag_help_test();

//! Function prompts the user to input test cases into a file.
//!     The function first verifies that the file was opened successfully.
//!
//! To finish the input process, the user must type 'end'.
//!     Before accepting input, the function displays the required input format to the user.
void print_flag_input();

//! If the flag is found, it writes information about failed test cases to the 'report.txt' file.
//!     The function first verifies that the file was opened successfully.
//!
//! Upon completion, a success message is displayed to the user, confirming that the operation has finished.
void print_flag_output();

#endif // FLAGS_FOR_TESTS_H