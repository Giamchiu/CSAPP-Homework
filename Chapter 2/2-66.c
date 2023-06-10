#include <stdio.h>

int leftmost_one(unsigned x) {
    x = x | x >> 1;
    x = x | x >> 2;
    x = x | x >> 4;
    x = x | x >> 8;
    x = x | x >> 16;
    return (x >> 1) + (x & 0x01);
}

int main() {
    printf("0x%.4X -> 0x%.4X\n", 0XFF00, leftmost_one(0xFF00));
    printf("0x%.4X -> 0x%.4X\n", 0X6600, leftmost_one(0x6600));
    printf("0x%.4X -> 0x%.4X\n", 0X00, leftmost_one(0X00));
    system("pause");
    return 0;
}