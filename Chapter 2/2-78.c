#include <stdio.h>

int divide_power2(int x, int k) {
    int W = sizeof(int) << 3;
    (((unsigned)x>>(W-1))&0x01) && (x += (1<<k)-1) ;
    return x >> k;
}

int main() {
    int x = 0x98765432;
    printf("%d %d\n", x / 2, divide_power2(x, 1));
    printf("%d %d\n", x / 4, divide_power2(x, 2));
  
    x = 0x01234567;
    printf("%d %d\n", x / 2, divide_power2(x, 1));
    printf("%d %d\n", x / 4, divide_power2(x, 2));  
    system("pause");
    return 0;
}

