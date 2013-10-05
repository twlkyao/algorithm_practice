#include<stdio.h>

#define MAX 50

/* int gcb(int a, int b) { */
/*     while (a != b) { */
/*         if (a > b) */
/*             a -= b; */
/*         else */
/*             b -= a; */
/*     } */
/*     return a; */
/* } */

int GCD(int num1, int num2) {
    if ( num1 % num2 == 0)
        return num2;
    else
        return GCD( num2, num1 % num2);
}

/* 数组翻转：杂技代码 */
void jugllingAct(char x[MAX], int rotdist, int n) {
    int i, valueGCB;
    int j, k, t;

    valueGCB = GCD(rotdist, n);
    /* printf("%d,%d,%d\n", valueGCB, rotdist, n); */

    for (i = 0; i < valueGCB; ++i) {
        t = x[i];
        j = i;
        while (1) {
            k = j + rotdist;
            if (k >= n)
                k -= n;
            if (k == i)
                break;
            x[j] = x[k];
            j = k;
        }
        x[j] = t;
    }
}

int main() {
    char x[MAX];
    int rotdist, n;

    scanf("%s%d%d", x, &rotdist, &n);
    jugllingAct(x, rotdist, n);

    printf("%s\n", x);
}