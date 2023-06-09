#include <stdio.h>

int int_shifts_are_arithmetic() {
    int val = 0xffffffff;
    val = val >> ((sizeof(int) * 8) - 1);
    return !(!(val ^ 0x01));
}

int main() {
    printf("%d\n", int_shifts_are_arithmetic());
    system("pause");
    return 0;
}