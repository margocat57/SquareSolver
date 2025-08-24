#include <stdio.h>

void clear_input_buffer(void) {
    int c = 0; 
    while ((c = getchar()) != '\n' && c != EOF) {;}
}
