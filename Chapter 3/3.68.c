/*
 * 
 * A = 9
 * 
 * B = 5
 * 
 */


typedef struct {
    int x[9][5]; /* Unknown constants A and B */
    long y;
} str1;
typedef struct {
    char array[5];
    int t;
    short s[9];
    long u;
} str2;
void setVal(str1 *p, str2 *q) {
    long v1 = q->t;
    long v2 = q->u;
    p->y = v1+v2;
}