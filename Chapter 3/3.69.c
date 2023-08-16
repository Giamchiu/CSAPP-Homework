/*
 * 
 * CNT = 7
 * 
 */

typedef struct {
    long idx;
    long x[4];
} a_struct;

typedef struct {
    int first;
    a_struct a[7];
    int last;
} b_struct;

void test(long i, b_struct *bp){
    int n = bp->first + bp->last;
    a_struct *ap = &bp->a[i];
    ap->x[ap->idx] = n;
}