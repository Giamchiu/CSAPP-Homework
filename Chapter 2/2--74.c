#include <stdio.h>

int tsub_ok(int x, int y) {
    int W = sizeof(int) << 3;
    y = ~(y) + 1;
    int sum = x + y;
    int overflow = (!((unsigned)x >> (W - 1)) && !((unsigned)y >> (W - 1)) && (((unsigned)(sum) >> (W - 1))))
                   || ((unsigned)x >> (W - 1)) && ((unsigned)y >> (W - 1)) && !(((unsigned)(sum) >> (W - 1)));
    return !((overflow) || !((y ^ (1 << (W - 1)))));
}

int main() {
    printf("%.8x - %.8x -> %d\n", 0, 0, tsub_ok(0x00000000, 0x00000000));
    printf("%.8x - %.8x -> %d\n", 0, 0x80000000, tsub_ok(0x00000000, 0x80000000));
    printf("%.8x - %.8x -> %d\n", 0x00000100, 0xffffffff, tsub_ok(0x00000100, 0xffffffff));
    printf("%.8x - %.8x -> %d\n", 0x80000001, 0x7fff0000, tsub_ok(0x80000001, 0x7fff0000));
    system("pause");
    return 0;
}
