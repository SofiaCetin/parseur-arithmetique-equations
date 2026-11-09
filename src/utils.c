#include "utils.h"

int str_in(char* s, char c){
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

size_t str_len(char* s){
    size_t i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

char* strcat(char *dest, const char *src){
    size_t i,j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}

int main(void){
    printf("%d", str_in("abcd", 'e'));
    char s[] = "bonjour";
    char* a = malloc(sizeof(s));
    if (a == NULL){
        return 1;
    }
    a = add_char("bonjour", 'p');
    printf("%s", a);
    return 0;
}