#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

#define TRUE 1
#define FALSE 0

int main(void) {
    char *path;
    path = (char*)malloc(sizeof(char) * 100);
    scanf("%99s", path);
    FILE *f = fopen(path, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    rewind(f);

    char *buf_data = malloc(fsize + 1);
    fread(buf_data, 1, fsize, f);
    buf_data[fsize] = '\0';

    // for (int i = 0; i < fsize; i++) {
    //     printf("%c", buf_data[i]);
    // }



    char* path_mod = "encoded.dat";
    srand((unsigned int)time(NULL));
    int* modifier_array = malloc(sizeof(int) * fsize);
    if (!modifier_array) return 1;

    if (is_file_empty(path_mod))  random_mod(fsize, modifier_array, path_mod);
    else mod_reader(fsize, modifier_array, path_mod);


    ASCII_coder(path_mod, buf_data, fsize, modifier_array);
    ASCII_reader(path_mod, fsize, modifier_array);



    free(modifier_array);
    free(path);
    free(buf_data);
    return 0;
}
