#include "math_lib.h"
#include <math.h>

/* cf before every math function here stands for
converted function prototype. Instead of directly
taking one, two or more args, they now take them 
all in one tab as a whole argument. So as to make
the math functions compatible with the struct */

Real cfsinl(const Real *args){
    return sinl(args[0]);
}

Real cfcosl(const Real *args){
    return cosl(args[0]);
}

Real cftanl(const Real *args){
    return tanl(args[0]);
}

Real cfsqrtl(const Real *args){
    return sqrtl(args[0]);
}

Real cflogl(const Real *args){
    return logl(args[0]);
}

Real cfexpl(const Real *args){
    return expl(args[0]);
}

Real cffabsl(const Real *args){
    return fabsl(args[0]);
}

Real cfpowl(const Real *args){
    return powl(args[0], args[1]);
}

Real cfminl(const Real *args){
    return args[0] > args[1] ? args[1] : args[0];
}

Real cfmaxl(const Real *args){
    return args[0] > args[1] ? args[0] : args[1];
}

const MathFunction FUNCTIONS[LIST_LENGTH] = {
    {"sin", cfsinl, 1},
    {"cos", cfcosl, 1},
    {"tan", cftanl, 1},
    {"sqrt", cfsqrtl, 1},
    {"log", cflogl, 1},
    {"exp", cfexpl, 1},
    {"abs", cffabsl, 1},
    {"pow", cfpowl, 2},
    {"min", cfminl, 2},
    {"max", cfmaxl, 2}
};