#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListEl{
    char* value;
    char* type;
    struct ListEl* next;
}ListEl;

typedef struct List{
    ListEl* first;
    size_t len;
}List;

List* create_list(ListEl* first);
void cons(List* list, ListEl* el);
int isListValid(List* list);
int isElValid(ListEl* el);

#endif