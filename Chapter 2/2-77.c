#include <stdio.h>

int A(int x) {
    return (x << 4) + x;
}

int B(int x) {
    return x - (x << 3);
}

int C(int x) {
    return (x << 6) - (x << 2);
}

int D(int x) {
    return (x << 4) - (x << 7);
}

int main() {
    printf("%d %d %d %d\n", A(1), B(1), C(1), D(1));
    printf("%d %d %d %d\n", A(2), B(2), C(2), D(2));
    printf("%d %d %d %d\n", A(-1), B(-1), C(-1), D(-1));
    printf("%d %d %d %d\n", A(-2), B(-2), C(-2), D(-2)); 
    system("pause");
    return 0;
}
