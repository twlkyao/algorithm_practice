#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 500

int scomp(char a[MAX], char b[MAX]) {
    return strcmp(a, b);
}

int main(void) {
    char word[MAX][MAX];
    int i = 0, j = 0;

    while (scanf("%s", word[i++]) != EOF) {
        printf("%s\n", word[i - 1]);
    }

    qsort(word, strlen(word), sizeof(word[MAX]), scomp);

    printf("\n\n");
    while (j++ < i) {
        printf("%s\n", word[j]);
    }
}