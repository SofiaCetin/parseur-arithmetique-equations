#include "mystr.h"
#include <stdlib.h>

const char NUMBERS[] = ".0123456789";
const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char OPERANDS[] = "+-*/=";

char* new_empty_str(void){
    char* res = malloc(sizeof(char));
    if (res == NULL){
        return NULL;
    }
    res[0] = '\0';
    return res;
}
int count_char(const char* s, char c){
    if (s == NULL){
        return -1;
    }
    int res = 0;
    while(*s != '\0'){
        if (*s == c){
            res++;
        }
        s++;
    }
    return res;
}

int any_c_in(const char* str, const char* input){
    if (str == NULL || input == NULL){
        return 0;
    }
    size_t i;
    size_t len = str_len(str);
    while(*input != '\0'){
        for(i = 0; i < len; i++){
            if (*(str + i) == *input){
                return 1;
            }
        }
        input++;
    }
    return 0;
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

char* str_add(char* dest, const char c){
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

/* Don't think we need this function anymore. Will prob delete that later
char* detect_number(const char* expr){
    if (expr == NULL){
        return NULL;
    }

    char* res = new_empty_str();
    if (res == NULL){
        return NULL;
    };

    while(*(expr) != '\0' && count_char(NUMBERS, *expr) != 0){
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
*/

char* strip(char* str){
    if (str == NULL){
        return NULL;
    }
    char* res = new_empty_str();
    if (res == NULL){
        return NULL;
    }
    while(*(str) != '\0'){
        if (*(str) != ' '){
            char* new = str_add(res, *(str));
            if (new == NULL){
                free(res);
                return NULL;
            }
            res = new;
        }
        str++;
    }
    return res;
}

char* char_to_str(char c){
    char* res = malloc(2 * sizeof(char));
    if (res == NULL){
        return NULL;
    }

    res[0] = c;
    res[1] = '\0';

    return res;
}

char str_to_char(char* str){
    char res = str[0];
    free(str);
    return res;
}

int str_ends_with(const char* str, const char* input){
    if (str == NULL || input == NULL || str_len(str) < str_len(input)){
        return -1;
    }

    size_t string_len = str_len(str);
    size_t input_len = str_len(input);
    size_t i = string_len - input_len;
    size_t j = 0;
    for (; i < string_len; i++, j++){
        if (*(str + i) != *(input + j)){
            return 0;
        }
    }

    return 1;
}

int str_cmp(const char* a, const char* b){
    if (a == NULL || b == NULL || str_len(a) != str_len(b)){
        return 0;
    }
    for (size_t i = 0; i <= str_len(a); i++){
        if (*(a + i) != *(b + i)){
            return 0;
        }
    }
    return 1;
}

int hasOneEqualSymbol(char* str){
    return count_char(str, '=') == 1;
}