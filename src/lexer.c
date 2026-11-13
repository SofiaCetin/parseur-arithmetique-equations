#include "lexer.h"

TokenList* tokenize(char* expr){
}

int main(void){
    char x[] = "1.23abcdfs232+34";
    char* test = detect_number(x);
    printf("%s", test);
    return 0;
}