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
    float_bits twice_f = float_twice(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&twice_f);
    
    f = -985.678;
    twice_f = float_twice(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&twice_f);
    
    f = __INT32_MAX__ + 1;
    twice_f = float_twice(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&twice_f);
    
    f = pow(2, 32);
    twice_f = float_twice(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&twice_f);

    unsigned uf=0xff000000;
    twice_f = float_twice(uf);
    printf("%8f -> %f\n", *(float*)&uf, *(float*)&twice_f);
    uf=0x7f800000;
    twice_f = float_twice(uf);
    printf("%8f -> %f\n", *(float*)&uf, *(float*)&twice_f);

    system("pause");
    
    return 0;
}
