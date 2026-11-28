#include "lexer.h"
#include "mystr.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


Token pre_token_type(char c){

    if (count_char(OPERANDS,c) > 0){
        return T_OPERAND;
    }
    if (count_char(ALPHABET,c) > 0){
        return T_ALPHA;
    }
    if (count_char(NUMBERS, c) > 0){
        return T_NUMBER;
    }
    if (c == '('){
        return T_LPAR;
    }
    if (c == ')'){
        return T_RPAR;
    }
    else{
        return UNDEF;
    }

}

List pre_tokenization(char* expr){
    if (expr == NULL || str_len(expr) < 1 || !hasOneEqualSymbol(expr)){
        return NULL;
    }

    Token type = pre_token_type(*expr);

    List res = new_list();
    char* str = char_to_str(*expr);
    if (res == NULL || str == NULL){
        return NULL;
    }
    append(res, str, type);
    expr++;

    while(*expr != '\0'){
        Token type = pre_token_type(*expr);
        char* str = char_to_str(*expr);
        if (res == NULL || str == NULL){
            return NULL;
        }
        append(res, str, type);
        expr++;
    }

    return res;
}

void tokenization(List l){
    if (l == NULL || isListEmpty(l)){
        ERROR("Liste null ou vide");
        return;
    }

    struct TokenCell* current = l->next;
    while (current != l){

        if (current->type == 0){
            // Check for undefined chars/symbols (ex: "2x+5$" is wrong)
            ERROR("Caractère non défini");
            delete_list(&l);
            exit(1);
        }

        // Search for successive types and group them to make the parsing easier
        int steps = detect_same_type(current);
        if (steps > 1){
            current = group_same_type(current, steps);
            continue;
        }

        current = current->next;
    }
}

int detect_same_type(struct TokenCell* element){
    /* one char after should return 1, 
    a number of n chars after should return n.
    basically tolds the tokenization function how many chars
    to group with the first char */

    if (element == NULL){
        ERROR("Element null");
        return -1;
    }

    int res = 0;
    struct TokenCell* current = element;
    while(current != NULL && current->type == element->type){
        res++;
        current = current->next;
    }

    return res;
}

struct TokenCell* group_same_type(struct TokenCell* element, int steps){
    // Group a successive type into one char
    if (element == NULL){
        ERROR("Element null");
        return NULL;
    }

    struct TokenCell* current = element->next;
    for (; steps > 1 ;steps--){
        element->value = str_add(element->value, *current->value);
        struct TokenCell* next = current->next;
        delete_element(current);
        current = next;
    }
    return current;
}