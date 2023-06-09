#include<stdio.h>

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    // unsigned mask = (unsigned)-1 >> k;
    unsigned mask = ~(1 << (sizeof(unsigned) * 8 - 1)) >> (k - 1);
    return xsra & mask; 
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;
    int mask = (xsrl >> ((sizeof(unsigned) * 8 - 1) - k) << (sizeof(unsigned) * 8 - k)) - 1;
    return ~xsrl ^ mask;
}

int main() {
    printf("srl\n%.8x -> %0.8x\n", 0x10000000, srl(0x10000000, 16));
    printf("%.8x -> %0.8x\n", 0xf0000000, srl(0xf0000000, 16));
    printf("sra\n%.8x -> %0.8x\n", 0x10000000, sra(0x10000000, 16));
    printf("%.8x -> %0.8x\n", 0xf0000000, sra(0xf0000000, 16));
    system("pause");
    return 0;
}