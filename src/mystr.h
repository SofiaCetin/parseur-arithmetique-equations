#ifndef MYSTR_H_
#define MYSTR_H_

#include <stdio.h>
#include <stdlib.h>

extern const char NUMBERS[];
extern const char ALPHABET[];
extern const char OPERANDS[];

int str_in(const char* s, char c);
size_t str_len(const char* s);
char* str_add(char *dest, char c);
char* detect_number(const char* expr);

#endif