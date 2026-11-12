#include "mystr.h"

int str_in(const char* s, char c){
    if (s == NULL){
        return 1;
    }
    while(*(s) != '\0'){
        if (*(s) == c){
            return 0;
        }
        s++;
    }
    return 1;
}

size_t str_len(const char* s){
    if (s == NULL){
        return 0;
    }
    size_t i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

char* str_add(char *dest, char c){
    if (dest == NULL){
        return NULL;
    }
    size_t len = str_len(dest);

    char* res = realloc(dest, len + 2);
    if (res == NULL){
        return NULL;
    }
    res[len] = c;
    res[len+1] = '\0';

    return res;
}