#include <stdio.h>

int A(int k){
    return -1<<k;
}

int B(int j,int k){
    return ~A(k)<<j;
}

int main() {
    printf("k = %d        -> %.8x\n",16,A(16)); 
    printf("j = %d k = %d -> %.8x\n",12,16,B(12,16)); 
    system("pause");
    return 0;
}