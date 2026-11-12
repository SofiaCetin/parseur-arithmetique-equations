#include "utils.h"

int isListValid(List* list){
    return list != NULL;
}

int isElValid(ListEl* el){
    return el != NULL && el->value != NULL && el->type != NULL;
}

List* create_list(ListEl* first){
    if (!isElValid(first))
        return NULL;
    List* res = malloc(sizeof(List));
    if (!isListValid(res))
        return NULL;
    res->first = first;
    res->len = 1;
    return res;
}

void cons(List* list, ListEl* el){
    if (!isListValid(list) || !isElValid(el)){
        return;
    }
    el->next = list->first;
    list->first = el;
}