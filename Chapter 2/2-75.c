#include <stdio.h>

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int W = sizeof(unsigned) << 3;
    int si_prod = signed_high_prod(x, y);
    unsigned un_prod;
    int sig_x = x >> (W - 1);
    int sig_y = y >> (W - 1);
    un_prod = si_prod + (sig_x * y) + (sig_y * x);
    return un_prod;
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
    int W = sizeof(__int64) << 3;
    __int64 mul = (__int64)x * y;
    mul >>= (W / 2);
    return mul;
}

int signed_high_prod(int x, int y) {
    int W = sizeof(__int64) << 3;
    __int64 mul = (__int64)x * y;
    mul >>= (W / 2);
    return mul;
}

int main() {
    printf("%.8x\n%.8x\n", another_unsigned_high_prod(0x12345678, 0xffffffff), unsigned_high_prod(0x12345678, 0xffffffff));
    system("pause");
    return 0;
}
