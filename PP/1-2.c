#include<stdio.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
/* #define N 10000000 */
#define N 100

int a[1 + N/BITSPERWORD];

void set(int i) {
    a[i>>SHIFT] |= (1<<(i & MASK));
}

void clr(int i) {
    a[i>>SHIFT] &= ~(1<<(i & MASK));
}

int  test(int i){
    return a[i>>SHIFT] & (1<<(i & MASK));
}

int main() {
    int i;
    printf("%d\n", test(4));

    for (i = 1; i <= N; i++)
        clr(i);

    printf("%d\n", test(4));
    set(4);
    printf("%d\n", test(4));
    clr(4);
    printf("%d\n", test(4));
}