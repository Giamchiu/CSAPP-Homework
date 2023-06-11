#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    int bytenum_max = 3;
    return ((int)word << ((bytenum_max - bytenum) << 3)) >> (bytenum_max << 3);
}

int main() {
    printf("0x%.8x %d -> 0x%.8x\n", 0x00112233, 0, xbyte(0x00112233, 0));
    printf("0x%.8x %d -> 0x%.8x\n", 0x00112233, 3, xbyte(0x00112233, 3));
    printf("0x%.8x %d -> 0x%.8x\n", 0xAA11FF33, 3, xbyte(0xAA11FF33, 3));
    printf("0x%.8x %d -> 0x%.8x\n", 0xAA11FF33, 1, xbyte(0xAA11FF33, 1));
    system("pause");
    return 0;
}