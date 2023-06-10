#include <stdio.h>

int odd_ones(unsigned x) {
    // Folding Method
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 0x01;
}

int main() {
    printf("%.8x -> %d\n", 0x10101010, odd_ones(0x10101010));
    printf("%.8x -> %d\n", 0x00000001, odd_ones(0x00000001));
    printf("%.8x -> %d\n", 0x1EF12380, odd_ones(0x1EF12380));
    system("pause");
    return 0;
}