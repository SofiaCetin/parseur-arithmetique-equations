#include "lexer.h"
#include "parser.h"
#include <stdlib.h>

int main(void){

    List l = pre_tokenization(strip("1 + log(2x) = 3"));
    if (l == NULL){
        printf("Error: exit with 1");
        exit(1);
    }
    show_list(l);
    tokenization(l);
    show_list(l);
    classify_tokens(l);
    show_list(l);
    delete_list(&l);


    return 0;
}