#include <stdio.h>
#include <math.h>

float u2f(unsigned x){
    return *(float *)&x;
}

float fpwr2(int x) {
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    if (x < 1-(pow(2,7)-1)-23) {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    } 
    else if (x < 1-(pow(2,7)-1)) {
        /* Denormalized result */
        exp = 0;
        frac = 1<<(unsigned)(x-(1-(pow(2,7)-1)-23));
    } 
    else if (x < (pow(2,7)-1)+1) {
        /* Normalized result. */
        exp = x+(pow(2,7)-1);
        frac = 0;
    } 
    else {
        /* Too big. Return +oo */
        exp = pow(2,8)-1;
        frac = 0;
    }

    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}

int main() {
    printf("2 ^ 0\t\t%d\n",fpwr2(0)==pow(2,0));
    printf("2 ^ 20\t\t%d\n",fpwr2(20)==pow(2,20));
    printf("2 ^ -20\t\t%d\n",fpwr2(-20)==pow(2,-20));
    printf("2 ^ 127\t\t%d\n",fpwr2(127)==pow(2,127));
    printf("2 ^ 128\t\t%d\n",fpwr2(128)==pow(2,128));
    printf("2 ^ -149\t%d\n",fpwr2(-149)==pow(2,-149));
    printf("2 ^ -150\t%d\n",fpwr2(+150)==pow(2,-150));
    system("pause");
    return 0;
}
