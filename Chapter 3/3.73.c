#include <stdio.h>

typedef enum {
    NEG = 0,
    ZERO = 1,
    POS = 2,
    OTHER = 3
} range_t;

range_t find_range(float x) {
    int result;
    asm volatile (
        "vxorps   %%xmm1, %%xmm1, %%xmm1\n\t"
        "vucomiss %%xmm1, %%xmm0\n\t"
        "ja       .POS\n\t"
        "je       .ZERO\n\t"
        "jb       .NEG\n\t"
        "movl     $3, %%eax\n\t"
        "jmp      .DONE\n\t"
        ".POS:\n\t"
        "movl     $2, %%eax\n\t"
        "jmp      .DONE\n\t"
        ".ZERO:\n\t"
        "movl     $1, %%eax\n\t"
        "jmp      .DONE\n\t"
        ".NEG:\n\t"
        "movl     $0, %%eax\n\t"
        ".DONE:\n\t"
        : "=a"(result)
        : "x"(x)
        :
    );
    return result;
}
