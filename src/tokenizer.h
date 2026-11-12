#ifndef TOKENIZE_H_
#define TOKENIZE_H_

typedef struct Operand{
    char* name;
    char* symbol;
}Operand;

typedef struct MathFunction{
    char* name;
    double (*function)(char* expr);
}MathFunction;

typedef struct MathConstant{
    char* symbol;
    double value;
}MathConstant;

char* detect_number(const char* expr);

#endif