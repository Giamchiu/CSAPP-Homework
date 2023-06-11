#include <stdio.h>

unsigned rotate_left(unsigned x, int n){
    int W = sizeof(int) * 8 * (!!n);
    return (x << n) | (x >> (W - n));
}

int main() {
    printf("n=%d -> 0x%.8x\n", 4, rotate_left(0x12345678, 4));
    printf("n=%d -> 0x%.8x\n", 20, rotate_left(0x12345678, 20));
    printf("n=%d -> 0x%.8x\n", 0, rotate_left(0x12345678, 0));
    system("pause");
    return 0;
}