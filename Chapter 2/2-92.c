#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    
    if (exp == 0xff && frac != 0)
        return f;
    
    return (!sign << 31) | (exp << 23) | frac;
}

int main() {
    float po_f = 9, ne_f = -po_f;
    
    printf("%d\n", *(unsigned*)&ne_f == float_negate(*(unsigned*)&po_f));
    
    po_f = -555, ne_f = -po_f;
    printf("%d\n", *(unsigned*)&ne_f == float_negate(*(unsigned*)&po_f));
    
    po_f = __INT32_MAX__ + 1, ne_f = -po_f;
    printf("%d\n", *(unsigned*)&ne_f == float_negate(*(unsigned*)&po_f));
    
    po_f = pow(2, 32), ne_f = -po_f;
    printf("%d\n", *(unsigned*)&ne_f == float_negate(*(unsigned*)&po_f));
    
    system("pause");
    
    return 0;
}
