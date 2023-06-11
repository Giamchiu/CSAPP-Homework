#include <stdio.h>

int fits_bits(int x, int n){
    x = (x ^ (x >> 31));
    return !(x >> (n - 1) ^ 0x00);
}

int main() {
    printf("x=%d n=%d -> %d\n", 0, 1, fits_bits(0, 1));
    printf("x=%d n=%d -> %d\n", -8, 4, fits_bits(-8, 4));
    printf("x=%d n=%d -> %d\n", 32, 6, fits_bits(32, 6));
    system("pause");
    return 0;
}