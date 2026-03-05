#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// Used to detect an error when opening a file | return error 3!
void is_file_open(const FILE* f) {
    if (f == NULL) { printf("Error in opening file\n"); exit(3); }
}

// Is the file empty or non-existent, empty 1 or 0
int is_file_empty(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) return 1;
    fseek(f, 0, SEEK_END); // fseek moves the position of the file pointer.
    long size = ftell(f);
    fclose(f);
    return size == 0;
}

// Reads information from the config.cfg file for the modifier_array array
void mod_reader(int dat_el, int mod[], const char* path) {
    FILE *f = fopen(path, "r"); is_file_open(f);
    for (int i = 0; i < dat_el; i++) {
        if (fscanf(f, "%d", &mod[i]) != 1) {
            mod[i] = 0; // for errors
        }
    }
    fclose(f);
}
// Writes new random numbers to the modifier_array array and to the config.cfg file
void random_mod(int dat_el, int mod_arr[], const char* path) {
    for (int i = 0; i < dat_el; i++) {
        mod_arr[i] = rand() % 15;
    }
    FILE* f = fopen(path, "w"); is_file_open(f);
    for (int i = 0; i < dat_el; i++) {
        fprintf(f, "%d ", mod_arr[i]);
    }
    fclose(f);
}

// Main encoder, encrypts using the ASCII table, dots mark the end of a character. Rewrites the string into data.dat.
void ASCII_coder(const char* path, char data[], int dat_el, int mod_arr[], int mod_able) {
    FILE* f = fopen(path, "w"); is_file_open(f);
    for (int i = 0; i < dat_el; i++) {
        int c = data[i];
        if (mod_able == TRUE) c -= mod_arr[i];
        fprintf(f, ".%d", c);
    }
    fclose(f);
}
// Reads from data.dat. All characters until a dot are converted into a number, then the last dot is returned back to the stream
void ASCII_reader(const char* path, int dat_el, int mod_arr[]) {
    FILE* f = fopen(path, "r"); is_file_open(f);
    int c, i = 0;
    do {
        c = fgetc(f);
        if (c == '.') {
            int num = 0;
            while ((c = fgetc(f)) >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            }
            if (mod_able == TRUE && i < dat_el)
                num += mod_arr[i];
            i++;
            if (c != EOF) ungetc(c, f);
            printf("%c", num);
            continue;
        }
    } while (c != EOF);
    fclose(f);
}
