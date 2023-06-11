#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes - (int) sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}

int main() {
    int maxbytes = sizeof(int) << 2;
    void *buf = malloc(maxbytes);
    int val;

    val = 0x11223344;
    copy_int(val, buf, maxbytes);
    printf("%.8x %.8x\n", val, *((int *) buf));

    val = 0x88776655;
    copy_int(val, buf, 0);
    printf("%.8x %.8x\n", val, *((int *) buf));

    system("pause");
    return 0;
}
