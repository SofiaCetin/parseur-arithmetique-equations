#ifndef MATH_LIB_H
#define MATH_LIB_H

#include <math.h>

typedef long double Real;

typedef struct MathFunction{
    const char* name;
    Real (*function)(Real);
}MathFunction;

typedef struct MathConstant{
    const char* symbol;
    Real value;
}MathConstant;

extern const MathFunction FUNCTIONS[];

#endif