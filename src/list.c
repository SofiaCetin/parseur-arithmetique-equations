#include "list.h"

int isListValid(TokenList* list){
    return list != NULL;
}

int isElValid(TokenEl* el){
    return el != NULL && el->value != NULL;
}

TokenList* create_list(TokenEl* first){
    if (!isElValid(first))
        return NULL;
    TokenList* res = malloc(sizeof(TokenList));
    if (!isListValid(res))
        return NULL;
    res->first = first;
    res->len = 1;
    return res;
}

void cons(TokenList* list, TokenEl* el){
    if (!isListValid(list) || !isElValid(el)){
        return;
    }
    el->next = list->first;
    list->first = el;
}