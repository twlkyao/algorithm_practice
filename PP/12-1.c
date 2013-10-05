#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bigrand() {
    return RAND_MAX*rand() + rand();
}

int randint(int l, int u){
    return l + bigrand() % (u - l + 1);
}

int main(void) {
    int r;

    srand((unsigned) time());

    r = randint(10, 1000);

    printf("%d\n", r);
    return 0;
}