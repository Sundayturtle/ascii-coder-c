#ifndef TASKS_FUNC_H
#define TASKS_FUNC_H

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void is_file_open(const FILE* f);
int is_file_empty(const char* path);
void mod_reader(int dat_el, int mod[], const char* path);
void random_mod(int dat_el, int mod_arr[], const char* path);
void ASCII_coder(const char* path, char data[], int dat_el, int mod_arr[], int mod_able);
void ASCII_reader(const char* path, int dat_el, int mod_arr[], int mod_able);

#endif