#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

/* Compute 2*f. If f is NaN, then return f. */
float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    
    if ((exp == 0xff) && (frac != 0))
        return f;
    else if (exp == 0xff - 1) {
        exp = 0xff;
        frac = 0;
    } else if ((exp != 0xff) && (exp != 0x00))
        exp += 1;
    else if (exp == 0x00)
        frac <<= 1;
    
    return (sign << 31) | (exp << 23) | frac;
}

int main() {
    float f = 10.555;
    float_bits absval_f = float_twice(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&absval_f);
    
    f = -985.678;
    absval_f = float_twice(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&absval_f);
    
    f = __INT32_MAX__ + 1;
    absval_f = float_twice(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&absval_f);
    
    f = pow(2, 32);
    absval_f = float_twice(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&absval_f);
    
    system("pause");
    
    return 0;
}
