#include <stdio.h>

unsigned f2u(float x) {
    unsigned *ptr = &x;
    return *ptr;
}

int float_less(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    return ((ux << 1) == (uy << 1)) ||
           (sx && !sy) ||
           (sx && sy && ux > uy) ||
           (!sx && !sy && ux < uy);
}

int main() {
    printf("%d\n", float_less(+0, -0));
    printf("%d\n", float_less(7.0, 14.0));
    printf("%d\n", float_less(14.0, 7.0));
    printf("%d\n", float_less(-7.0, -14.0));
    printf("%d\n", float_less(-14.0, -7.0));
    printf("%d\n", float_less(7.0, -14.0));
    printf("%d\n", float_less(-7.0, 14.0));
    system("pause");
    return 0;
}
