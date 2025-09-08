//! @file
#include <stdio.h>
#ifndef STRUCTURES_CONSTS_H
#define STRUCTURES_CONSTS_H

//! String which will be displayed to user when input of coefficents is incorrect
const char* const ERROR_INPUT = "Ошибка ввода! Пожалуйста, введите три числа в указанном формате.\n";
//! Name of file with tests
const char* const NAME_FILE = "tests_for_solver.txt";
//! Comparison Precision
const double EPSILON = 1e-15;


//! For quantity of solutions
enum number_solutions {
    ZERO = 0, //!< no solutions
    ONE = 1, //!< one solution
    TWO = 2, //!< two solutions
    INFINITE = 3 //!< infinite solutions
}; 

//! For indicator of linear equation
enum is_linear {
    YES = 1, //!< equation is linear
    NO = 0 //!< equation is not linear
};

//! Structure for Equation Coefficients
struct equation_params{
    double coef_a; //!< x^2 coefficient 
    double coef_b; //!< x coefficient 
    double coef_c; //!< constant coefficent
};

//! Structure for Storing Input Parameters
struct equation_params_input {
    struct equation_params coefficents; //!< Structure containing equation coefficients
    const char *msg_error_input; //!< Pointer to the string when the input format is invalid
    int is_exit; //!< Exit request indicator
};

//! Structure for Solutions
struct solutions{
    double solution_x1; //!< root with the larger value
    double solution_x2; //!< root with the smaller value
    number_solutions number_of_solutions; //!< quantity of solutions of equation
    is_linear linear_eq; //!< indicator that the equation is linear
};

//! Structure for storing parameters for tests
struct equation_params_and_solutions{
    struct equation_params equation_params_for_tests; //!< coefficents for equations used in tests
    struct solutions solutions_for_tests; //!< ideal solutions for equations used in tests
};

//! Needed to indicate if digits needed to be parsed
enum types_for_flag_main {
    ARG_BOOL_TYPE = 0,  //!< this indicates, that digits doesn't needed to be parsed after flags
    ARG_NUMBER_TYPE = 1 //!< this indicates, that digits needed to be parsed after flags
};

//!< Structure for parsing flags of console
struct handling_flags
{
    const char* flag_short; //!< short version of flag(for ex. -h for flag --help)
    const char* flag_long; //!< long version of flag
    enum types_for_flag_main type; //!< to indicate if digits needed to be parsed
    bool is_flag; //!< is flag found in input
    double* coef; //!< Pointer to coefficent(needed to parse coefficent in input -a 1 -b 2 -c 3)
};


struct flags_for_tests{
    const char* flag_test; 
    bool is_flag_test; 
};


enum argument_main_type{
    HELP = 0, 
    COEF_A = 1, 
    COEF_B = 2, 
    COEF_C = 3  
};


enum argument_test_type{
    HELP = 0, 
    H = 1, 
    INPUT = 2, 
    OUTPUT = 3 
};

#endif //STRUCTURES_CONSTS_H