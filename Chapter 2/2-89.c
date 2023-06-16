#include <stdio.h>

/* right */
int A(double dx, float x) {
    return (float) x == (float) dx;
}

/* false y=Tmin */
int B(double dx, double dy, int x, int y) {
    return dx - dy == (double) (x - y);
}

/* right */
int C(double dx, double dy, double dz) {
    return (dx + dy) + dz == dx + (dy + dz);
}

/* right */
int D(double dx, double dy, double dz) {
    return (dx * dy) * dz == dx * (dy * dz);
}

/* false 0/0 != 5/5 */
int E(double dx, double dz) {
    return dx / dx == dz / dz;
}

int main() {
    int x = rand();
    int y = rand();
    int z = rand();
    
    /* Convert to double */
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;
    
    printf("%d\n", A(dx, x));
    printf("%d\n", B(dx, (double) (int) (__INT_FAST32_MAX__ + 1), x, (__INT_FAST32_MAX__ + 1)));
    printf("%d\n", C(dx, dy, dz));
    printf("%d\n", D((double) (int) 0x64e73387, (double) (int) 0xd31cb264, (double) (int) 0xd22f1fcd));
    printf("%d\n", E((double) (int) 0, dy));
    
    system("pause");
    return 0;
}
