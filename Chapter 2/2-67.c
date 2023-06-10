#include <stdio.h>

int bad_int_size_is_32() {
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;
    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;
    /* set_msb is nonzero when word size >= 32
    beyond_msb is zero when word size <= 32 */
    return set_msb && !beyond_msb;
}

int int_size_is_32(){
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16bit() {
    __int16 set_msb = 1 << 15;
    __int16 beyond_msb = set_msb << 1;
    __int16 set_msb2 = set_msb << 15 << 1;
    __int16 beyond_msb2 = set_msb2 << 1;
    return (set_msb && !beyond_msb) || (set_msb2 && !beyond_msb2);
}

int main() {
    printf("%d\n", int_size_is_32());
    printf("%d\n", int_size_is_32_for_16bit());
    system("pause");
    return 0;
}