#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Dict{
    char* keys;
    double* values;
    int size;
}Dict;

static Dict create_dict(char* keys, double* values, int size);
static void add_key_value(Dict dict, char key, double value);
static void show_dict(Dict dict);

static int str_in(char* s, char c);
static char* add_char(char* s, char c);
static int str_len(char* s);

#endif