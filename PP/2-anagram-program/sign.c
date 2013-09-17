#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int charcmp(char *a, char *b) {
    return *a - *b;
}

int main(void) {
    char word[MAX], sig[MAX];

    while (scanf("%s", word) != EOF) {
        strcpy(sig, word);
        qsort(sig, strlen(sig), sizeof(char), charcmp);
        printf("%s %s\n", sig, word);
    }

    return 0;
}