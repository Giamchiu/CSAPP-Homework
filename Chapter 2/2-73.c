#include <stdio.h>

int saturating_add(int x, int y) {
    int W = sizeof(int) << 3;
    int sum = x + y;
    int po_over = !((unsigned)x >> (W - 1)) && !((unsigned)y >> (W - 1)) && ((unsigned)sum >> (W - 1));
    int ne_over = ((unsigned)x >> (W - 1)) && ((unsigned)y >> (W - 1)) && !((unsigned)sum >> (W - 1));
    (po_over && (sum = __INT32_MAX__)) || (ne_over && (sum = __INT32_MAX__ + 1));
    return sum;
}

int main() {
    printf("%.8x + %.8x -> %.8x\n", __INT32_MAX__, 0X5555, saturating_add(__INT32_MAX__, 0X5555));
    printf("%.8x + %.8x -> %.8x\n", __INT32_MAX__ + 1, 0Xffff0000, saturating_add(__INT32_MAX__ + 1, 0Xffff0000));
    printf("%.8x + %.8x -> %.8x\n", 0x0011, 0x1100, saturating_add(0x0011, 0x1100));
    printf("%.8x + %.8x -> %.8x\n", 0xffffffff, 0x01, saturating_add(0xffffffff, 0x01));
    system("pause");
    return 0;
}
