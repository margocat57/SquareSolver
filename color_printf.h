//! @file
#ifndef COLOR_PRINTF_H
#define COLOR_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


#define RED(STR) "\033[31m"STR"\033[0m\n"

//! Prints text in different colors depending on the output stream.
//!
//! @param [in] OUTPUT Stream/FILE pointer where text should be written
//! @param [in] fmt Format string (printf-style)
//! @param ... Variable arguments for the format string
//!
//! @note This function is particularly useful for displaying equation solutions
//!     where errors need to be highlighted in red
void my_printf(FILE *OUTPUT, const char* string  ...);

#endif //COLOR_PRINTF_H