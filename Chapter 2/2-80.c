#include <stdio.h>

int threefourths(int x) {
    int W = sizeof(int) << 3;
    int a = x & ~0x03;
    int b = x & 0x03;
    int ad4 = a >> 2;
    int ad4m3 = (ad4 << 1) + ad4;
    int bm3 = (b << 1) + b;
    int bias = 0x03;
    (x >> (W - 1)) && (bm3 += bias);
    int bm3d4 = bm3 >> 2;
    return ad4m3 + bm3d4;
}

int main() {
    for (int x = 8; x <= 12; x++)
        printf("%d * 3/4 = %d\n", x, threefourths(x));
    
    for (int x = -8; x >= -12; x--)
        printf("%d * 3/4 = %d\n", x, threefourths(x));
    
    system("pause");
    return 0;
}

