#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

/* Compute |f|. If f is NaN, then return f. */
float_bits float_absval(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    
    if (exp == 0xff && frac != 0)
        return f;
    
    return ((sign & 0x00) << 31) | (exp << 23) | frac;
}

int main() {
    float f = 9.123456;
    float_bits absval_f = float_absval(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&absval_f);
    
    f = -6789.987793;
    absval_f = float_absval(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&absval_f);
    
    f = __INT32_MAX__ + 1;
    absval_f = float_absval(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&absval_f);
    
    f = pow(2, 32);
    absval_f = float_absval(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&absval_f);
    
    system("pause");
    
    return 0;
}
