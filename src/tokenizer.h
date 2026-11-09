#ifndef TOKENIZE_H_
#define TOKENIZE_H_

const char Numbers[] = "0123456789";
const char Alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

typedef struct Operand{
    char* name;
    char* symbol;
}Operand;

typedef struct MathFunction{
    char* name;
    double (*function)(char* expr);
}MathFunction;

static double detect_number(char* expr);

#endif