#include <stdio.h>

int any_odd_one(unsigned x) {
    return !((x & 0xaaaaaaaa) ^ 0xaaaaaaaa);
}

int main() {
    printf("%.8x -> %d\n", 0x00, any_odd_one(0x00));
    printf("%.8x -> %d\n", 0xffffffff, any_odd_one(0xffffffff));
    printf("%.8x -> %d\n", 0xaaaaaaaa, any_odd_one(0xaaaaaaaa));
    system("pause");
    return 0;
}