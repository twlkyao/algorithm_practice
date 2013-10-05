#include<stdio.h>
#include<stdlib.h>

int x[10001];


int bigrand() {
    return RAND_MAX*rand() + rand();
}

int randint(int l, int u){
    return l + bigrand() % (u - l + 1);
}

void swap(int a, int b) {
    int temp;
    temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}

int main(void) {
    int i, r;
    int k = 5;
    int n = 10000;

    for (i = 0; i < n; ++i)
        x[i] = i;

    for (i = 0; i < k; ++k) {
        swap(i, randint(i, n - 1));
        printf("%d\n", x[i]);
    }

    return 0;
}