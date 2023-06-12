#include <stdio.h>

int lower_one_mask(int n) {
    int W = sizeof(int) << 3;
    return (unsigned)-1 >> (W - n);
}

int main() {
    printf("%.2d -> 0x%.8X\n", 6, lower_one_mask(6));
    printf("%.2d -> 0x%.8X\n", 17, lower_one_mask(17));
    printf("%.2d -> 0x%.8X\n", 32, lower_one_mask(32));
    system("pause");
    return 0;
}