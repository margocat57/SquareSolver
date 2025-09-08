#include <stdio.h>
#include <stdlib.h> // Для NULL

#include "structures_consts.h"

static FILE *current_output = NULL;

FILE* get_output_file(void) {
    if (current_output == NULL) {
        return stderr;
    }
    return current_output;
} 

void set_output_file(FILE *output_to_file) {
    current_output = output_to_file;
}

