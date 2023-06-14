#include <stdio.h>
#include <stdlib.h>

/* 
 * 0,when x or y is INT_MIN
 */
int A(int x,int y){
    return (x < y) == (-x > -y);
}

/* 
 * ((x+y)<<4) + y - x
 * ->
 * (x << 4) + (y << 4) + y - x
 * ->
 * x*16 + y*16 + y - x
 * ->
 * x*15 + y*17  
 * right
 */
int B(int x,int y){
    return ((x + y) << 4) + y - x == 17 * y + 15 * x;
}

/*
 * ~(x+y)
 * ->
 * ~(x+y) + 1 - 1
 * ->
 * -(x+y) -1
 * ->
 * -x + -y -1
 * ->
 * ~x + 1 + ~y + 1 - 1
 * ->
 * ~x + ~y + 1
 * right
 */
int C(int x,int y){
    return ~x + ~y + 1 == ~(x + y);
}

/*
 * x-y = ux-uy
 * ->
 * -(y-x) = ux-uy
 * right
 */
int D(int x,int y){
    int ux, uy;
    ux = (unsigned)x;
    uy = (unsigned)y;
    return (ux - uy) == -(unsigned)(y - x);
}

/*
 * ((x >> 2) << 2) = x & ~0x03
 * ->
 * x - 00/01/10/11
 * ->
 * ((x >> 2) << 2) <= x
 * right
 */
int E(int x,int y){
    return ((x >> 2) << 2) <= x;
}

int main() {
    int x, y;
    x = rand();
    y = rand();
    printf("%d\n", A(x, __INT32_MAX__ + 1));
    printf("%d\n", B(x, y));
    printf("%d\n", C(x, y));
    printf("%d\n", D(x, y));
    printf("%d\n", E(x, y));
    system("pause");
    return 0;
}
