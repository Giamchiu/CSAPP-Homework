#include <stdio.h>

int main() {
    int a;
    scanf("%x", &a);
    printf("%d\n",
           (!(a ^ 0xffffffff)) ||
           (!(a ^ 0x00000000)) ||
           (!((a << (3 * 8)) ^ 0xff000000)) ||
           (!((a >> (3 * 8)) ^ 0x00000000))
          );
    system("pause");
    return 0;
}
