#include <stdio.h>

/*
 * bias = 2^(15 - 1) - 1
 * 0 0000...(15) 0 000...(62)1 2^(1 - bias - 63)
 * 0 000...(14)1 1 0000...(63) 2^(1 - bias)
 * 0 111...(14)0 1 1111...(63) 2^bias * (2 - (2^-63))
 */

int main() {
    system("pause");
    return 0;
}
