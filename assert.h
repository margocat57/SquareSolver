#ifndef ASSERT_H
#define ASSERT_H
#include <stdlib.h>

//! Checks if condition is correct, if it is incorrect outputs to stderr string, that is set in arguments
//!     also outputs to stderr name of file, function and line where mistake was found a
//!     Call the exit function with exit status EXIT_FAILURE
//!
//! @param [in] condition Condition will be checked
//! @param [in] string String will be output
//! @param [in] ... Variable arguments for the format string

#define MY_ASSERT(condition, string, ...) \
    if(condition == false) { \
        fprintf(stderr, string __VA_OPT__(,) __VA_ARGS__);\
        fprintf(stderr, "\n Ошибка в файле: %s, Ошибка в функции: %s, Ошибка в строке: %d\n", __FILE__,  __func__, __LINE__);\
        exit(EXIT_FAILURE); \
    }

#endif //ASSERT_H 