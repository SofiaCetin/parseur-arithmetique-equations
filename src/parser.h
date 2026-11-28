#include "lexer.h"
#include "mystr.h"
#include "math_lib.h"

void classify_tokens(List l);
const MathFunction* ends_with_any(const char* str, const MathFunction* l);