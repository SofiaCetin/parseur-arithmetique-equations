#include "mystr.h"

const char NUMBERS[] = ".0123456789";
const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char OPERANDS[] = "+-*/";

int str_in(const char* s, char c){
    if (s == NULL){
        return 1;
    }
    while(*s != '\0'){
        if (*s == c){
            return 0;
        }
        s++;
    }
    return 1;
}

int any_c_in(const char* str, const char* input){
    if (str == NULL || input == NULL){
        return 1;
    }
    size_t i;
    while(*input != '\0'){
        for(i = 0; i < len(str) - 1; i++){
            if (*(str + i) == *input){
                return 0;
            }
        }
        input++;
    }
    return 1;
};


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

char* detect_number(const char* expr){
    if (expr == NULL){
        return NULL;
    }

    char* res = malloc(sizeof(char));
    if (res == NULL){
        return NULL;
    };

    *res = '\0';
    while(*(expr) != '\0' && str_in(NUMBERS, *(expr)) == 0){
        char* new = str_add(res, *(expr));
        if (new == NULL){
            free(res);
            return NULL;
        }
        res = new;
        expr++;
    }
    return res;
}