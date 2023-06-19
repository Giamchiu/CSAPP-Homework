#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

int bits_length(int val) {
    if (val == 0x80000000)
        return 31;

    int length = 0;
    unsigned uval = (unsigned) val;

    while (uval >= (1 << length))
        length++;

    return length - 1;
}

/* Compute (float) i */
float_bits float_i2f(int i) {
    if (i == 0)
        return 0;

    unsigned sign = (unsigned) i >> 31;

    if (sign == 1)
        i = -i;

    int k = bits_length(i);
    unsigned bias = pow(2, 7) - 1;
    unsigned exp = k + bias;
    unsigned frac;

    if (k <= 23)
        frac = (i - (int) pow(2, k)) << (23 - k);
    else {
        frac = ((i - (int) pow(2, k)) + ((1 << (k - 23)) - 1)) >> (k - 23);

        if (frac >> 23 != 0) {
            frac = 0;
            exp += 1;
        }  
    }  

    return (sign << 31) | (exp << 23) | frac;
}

int main() {
    int i = 0;
    unsigned f = float_i2f(i);
    printf("%d %f %d\n", i, *(float*)&f, i - (int)(*(float*)&f)); 

    i = 8;
    f = float_i2f(i);
    printf("%d %f %d\n", i, *(float*)&f, i - (int)(*(float*)&f));

    i = -8;
    f = float_i2f(i);
    printf("%d %f %d\n", i, *(float*)&f, i - (int)(*(float*)&f)); 

    i = __INT32_MAX__;
    f = float_i2f(i);
    printf("%d %f %d\n", i, *(float*)&f, i - (int)(*(float*)&f));

    i = pow(-2,31);
    f = float_i2f(i);
    printf("%d %f %d\n", i, *(float*)&f, i - (int)(*(float*)&f));

    system("pause");   
    return 0;
}
