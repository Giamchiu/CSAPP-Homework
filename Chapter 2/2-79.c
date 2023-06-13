#include <stdio.h>

int mul3div4(int x) {
    int W = sizeof(int) << 3;
    int mul3 = (x << 1) + x;
    (((unsigned)mul3 >> (W - 1)) & 0x01) && (mul3 += (1 << 2) - 1);
    return mul3 >> 2;
}

int main() {
    printf("%d %d\n", mul3div4(10), 3 * 10 / 4);
    printf("%d %d\n", mul3div4(-10), 3 * (-10) / 4);  
    system("pause");
    return 0;
}
