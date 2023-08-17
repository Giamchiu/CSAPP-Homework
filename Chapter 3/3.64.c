/*
 * A.
 * xA + L(i*S*T + T*j + k)
 * 
 * B.
 * k + 65*i + 13*j
 * (3640 / 8) / 65 = 7
 */

long A [7] [5] [13];

long store_ele(long i, long j, long k, long *dest){
    *dest = A[i][j][k];
    return sizeof(A);
}
//%rax 13*j 
//%rdi 65*i+13*j
//%rdx k+65*i+13*j i*T(13)*S(5)+T(13)*j+k 56