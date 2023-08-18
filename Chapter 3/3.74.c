#include <stdio.h>

typedef enum {
    NEG = 0,
    ZERO = 1,
    POS = 2,
    OTHER = 3
} range_t;

range_t find_range(float x) {
    int result;
    asm (
        "vxorps   %%xmm1, %%xmm1, %%xmm1\n\t"
        "vucomiss %%xmm1, %1\n\t"
        "movl     $3, %%eax\n\t"
        "movl     $0, %%r8d\n\t"
        "movl     $1, %%r9d\n\t"
        "movl     $2, %%r10d\n\t"
        "cmova    %%r10d, %%eax\n\t"
        "cmovb    %%r8d, %%eax\n\t"
        "cmove    %%r9d, %%eax\n\t"
        "movl     %%eax, %0\n\t"
        : "=r"(result)
        : "x"(x)
        : "eax", "r8", "r9", "r10"
    );
}