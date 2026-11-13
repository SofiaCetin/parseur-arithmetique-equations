#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef enum {
    UNDEF,
    T_NUMBER,
    T_VARIABLE,
    T_CONSTANT,
    T_FUNCTION,
    T_LPAR,
    T_RPAR,
    T_EQUAL,
    T_OPERAND
}Token;

typedef struct TokenEl{
    char* value;
    Token type;
    struct TokenEl* next;
}TokenEl;

typedef struct TokenList{
    TokenEl* first;
    size_t len;
}TokenList;

TokenList* create_list(TokenEl* first);
void cons(TokenList* list, TokenEl* el);
int isListValid(TokenList* list);
int isElValid(TokenEl* el);

#endif