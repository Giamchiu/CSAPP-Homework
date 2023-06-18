#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

/*
 * Compute (int) f.
 * If conversion causes overflow or f is NaN, return 0x80000000
 */
int float_f2i(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = pow(2, 7) - 1;

    if (((exp == 0xff) && (frac != 0)) || ((int)(exp - bias) >= 32))
        return 0x80000000;
    else if ((int)(exp - bias) < 0)
        return 0x00;

    /* Example conversions:
     *     351 = 351/256 * 2^8 
     * (1.xxx) = 95/256 * 2^8
     *         = 0 10000111 01011111000000000000000
     *         = 0x43af8000
     *
     *   351.5 = 703 * 2^-1
     *         = 703/512 *2^9 * 2^-1
     * (1.xxx) = 191/512 *2^9 * 2^-1
     *         = 0 10001000 0101111110000 * 2^-1
     *         = 0 10000111 01011111100000000000000
     *         = 0x43afc000
     *
     * 0 01111110 11001100110011001100110
     * 0 10011101 0000000
     */

    if (exp - bias > 23)
        return pow(-1, sign) * ((frac << ((exp - bias) - 23)) + pow(2, exp - bias));
    else
        return pow(-1, sign) * ((frac >> (23 - (exp - bias))) + pow(2, exp - bias));
}

int main() {
    float a = 0;
    printf("%.2f %d \n", a, float_f2i(*(unsigned*)&a));

    a = 351;
    printf("%.2f %d \n", a, float_f2i(*(unsigned*)&a));

    a = 351.5;
    printf("%.2f %d \n", a, float_f2i(*(unsigned*)&a));

    a = -351.5;
    printf("%.2f %d \n", a, float_f2i(*(unsigned*)&a));

    a = 0.9;
    printf("%.2f %d \n", a, float_f2i(*(unsigned*)&a));

    a = -0.9;
    printf("%.2f %d \n", a, float_f2i(*(unsigned*)&a));

    a = pow(2, 30) + pow(2, 29);
    printf("%.2f %d \n", a, float_f2i(*(unsigned*)&a));

    a = pow(-2, 31);
    printf("%.2f %d \n", a, float_f2i(*(unsigned*)&a));

    //system("pause");
    return 0;
}
