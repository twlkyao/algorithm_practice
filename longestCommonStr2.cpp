/*
Description: 求一个字符串最长重复子串

链接：编程珠玑15.2

基本算法描述:
先对后缀数组进行排序，然后比较相邻字符串的前驱，得出最长公共前驱
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define MAXN 5000000
char c[MAXN], *a[MAXN];         // a为字符指针数组"后缀数组"

int pstrcmp(char **a, char **b) {
    return strcmp(*a, *b);
}

int comlen(char *p, char *q) {
    int i = 0;
    while (*p && (*p++ == *q++))
        i++;
    return i;
}

int main() {
    int n = 0, i, maxlen = -1, maxi;
    char ch;

    while ((ch = getchar()) != EOF) {
        a[n] = &c[n];
        c[n++] = ch;
    }
    c[n] = 0;

    qsort(a, n, sizeof(char *), pstrcmp);

    for (i = 0; i < n; ++i) {
        if (comlen(a[i], a[i+1]) > maxlen) {
            maxlen = comlen(a[i], a[i+1]);
            maxi = i;
        }
    }

    printf("%.*s\n", maxlen, a[maxi]);
}