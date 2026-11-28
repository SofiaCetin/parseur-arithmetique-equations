#include "parser.h"
#include <stdlib.h>

void classify_tokens(List l){
    // Checker for the equation syntax
    if (l == NULL || isListEmpty(l)){
        ERROR("Liste null ou vide");
        return;
    }

    struct TokenCell* current = l->next;
    while (current != l){

        if (current->type == 2){
            if (current->next->type == 3){
                // If an alpha type is followed by a left parenthesis, it could be a function or a factor
                const MathFunction* func = ends_with_any(current->value, FUNCTIONS);
                if (func != NULL){
                    printf("We have a function: %s\n", func->name);
                }
                else{
                    printf("We don't have a function: %s\n", current->value);
                }
            }
        }

        if (current->type == 5){
            if (str_len(current->value) > 1){
                ERROR("Two operands cannot follow each other");
                exit(1);
            }
        }

        current = current->next;
    }

}

const MathFunction* ends_with_any(const char* str, const MathFunction* l){
    if (str == NULL || l == NULL){
        return NULL;
    }

    for (int i = 0; i < LIST_LENGTH - 1; i++){
        if (str_ends_with(str, ((l + i)->name)) == 1){
            return l + i;
        }
    }

    return NULL;
}