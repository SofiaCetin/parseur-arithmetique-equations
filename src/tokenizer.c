#include "tokenizer.h"
#include "mystr.h"
#include "utils.h"

const char Numbers[] = ".0123456789";
const char Alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char Operands[] = "+-*/()";

char* detect_number(const char* expr){
    if (expr == NULL){
        return NULL;
    }

    char* res = malloc(sizeof(char));
    if (res == NULL){
        return NULL;
    };

    *res = '\0';
    while(*(expr) != '\0' && str_in(Numbers, *(expr)) == 0){
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

int isEquValid(const char* equ){

}

int main(void){
    char x[] = "1.23abcdfs232+34";
    char* test = detect_number(x);
    printf("%s", test);
    return 0;
}