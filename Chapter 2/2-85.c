#include <stdio.h>

/*
 * A
 * bias = 2^(k-1) - 1
 * V = 2^E * M
 * s = 1 , k = 8 , n = 23
 * 7.0 = 0 10000001 11000000000000000000000
 * - > 
 * 40e00000
 * B
 * f = 0.111111... , e = bias<<1     
 * ->
 * 0 bisa<<1 11111111111111111111111
 * C
 * f = 0 , E = 1 - bias
 * V = 2^(1-bias) 1-127=-126
 * reciprocal
 * V = 1/(2^(1-bias)) = 2^-(1-bias) = 2^(bias-1)
 * E = (bias-1) , e = bias + E
 * ->
 * 0 11111101 00000000000000000000000
 */

int main() {
    
    
    system("pause");
    return 0;
}
