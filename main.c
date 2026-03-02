#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

#define TRUE 1
#define FALSE 0

int main(void) {
    // Main settings (user friendly)
    char* path = "data.dat";
    char* path_mod = "mod.cfg";
    char data[] = "Hello from STURTLE";
    int inter_mod = 10;
    /* int use_data = TRUE; // will be previously set values changed to new? default > TRUE */ //will appear in the future
    int mod_able = TRUE; // on / off modifier
    int generate = TRUE;
    // Another variables
    srand(time(NULL) - inter_mod);
    int data_el = sizeof(data) / sizeof(char) - 1;
    int* modifier_array = malloc(sizeof(int) * data_el);
    if (!modifier_array) return 1;

    if (generate || is_file_empty(path_mod))  random_mod(data_el, modifier_array, path_mod);
    else mod_reader(data_el, modifier_array, path_mod);

    ASCII_coder(path, data, data_el, modifier_array, mod_able);
    ASCII_reader(path, data_el, modifier_array, mod_able);

    free(modifier_array);
    return 0;
}
