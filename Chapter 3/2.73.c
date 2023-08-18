typedef enum {
    NEG = 0,
    ZERO = 1,
    POS = 2,
    OTHER = 3
} range_t;

range_t find_range(float x) {
    int result;
    asm (
        "vxorps %%xmm1, %%xmm1, %%xmm1\n\t"
        "vucomiss %%xmm0, %%xmm1\n\t"
        "ja .NEG\n\t"
        "je .ZERO\n\t"
        "jb .POS\n\t"
        ".NEG:\n\t"
        "movl $0, %0\n\t"
        "jmp .DONE\n\t"
        ".ZERO:\n\t"
        "movl $1, %0\n\t"
        "jmp .DONE\n\t"
        ".POS:\n\t"
        "movl $2, %0\n\t"
        ".DONE:"
        : "=r"(result)
        : "x"(x)
    );
    return result;
}
