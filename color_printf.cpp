#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define COLOR_RED     "\033[31m"
#define COLOR_RESET   "\033[0m\n"

void my_printf(FILE *OUTPUT, const char* string ...){
    va_list args;
    va_start(args, string);
    if (OUTPUT == stderr) {
        fprintf(OUTPUT, COLOR_RED);
        vfprintf(OUTPUT, string, args);
        fprintf(OUTPUT, COLOR_RESET);
    }
    else {
        vfprintf(OUTPUT, string, args);
        fprintf(OUTPUT, "\n");
    }
    va_end(args);
}

