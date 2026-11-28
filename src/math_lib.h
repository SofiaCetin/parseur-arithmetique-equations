#ifndef MATH_LIB_H
#define MATH_LIB_H

#define LIST_LENGTH 10

typedef long double Real;

typedef struct MathFunction{
    const char* name;
    Real (*function)(const Real *args);
    int argc;
}MathFunction;

typedef struct MathConstant{
    const char* symbol;
    Real value;
}MathConstant;

Real cfsinl(const Real *args);
Real cfcosl(const Real *args);
Real cftanl(const Real *args);
Real cfsqrtl(const Real *args);
Real cflogl(const Real *args);
Real cfexpl(const Real *args);
Real cffabsl(const Real *args);
Real cfpowl(const Real *args);
Real cfminl(const Real *args);
Real cfmaxl(const Real *args);

extern const MathFunction FUNCTIONS[];

#endif