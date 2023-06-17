#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    
    if ((exp == 0xff) && (frac != 0))
        return f;
    else if (exp == 1) {
        exp = 0;
        frac = (frac >> 1) | 0x400000;
    } else if (exp == 0)
        frac >>= 1;
    else if (exp != 0xff)
        exp -= 1;
    
    return (sign << 31) | (exp << 23) | frac;
}

int main() {
    float f = 10.555;
    float_bits half_f = float_half(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&half_f);
    
    f = -985.678;
    half_f = float_half(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&half_f);
    
    f = __INT32_MAX__ + 1;
    half_f = float_half(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&half_f);
    
    f = pow(2, 32);
    half_f = float_half(*(unsigned*)&f);
    printf("%f -> %f\n", f, *(float*)&half_f);
    
    unsigned uf = 0x01;
    half_f = float_half(uf);
    printf("%.50f -> %.50f\n", *(float*)&uf, *(float*)&half_f);

    uf = 0x7f800000;
    half_f = float_half(uf);
    printf("%f -> %f\n", *(float*)&uf, *(float*)&half_f);
    
    system("pause");
    
    return 0;
}
