#include<stdio.h>
#include<string.h>

#define M 7
#define N 6

int count[M+1][N+1];
char lcss[M+N];

int max(int a, int b) {
    return a > b ? a : b;
}

int LCSLenth(char *a, char *b, int m, int n) {
    int i, j;
    for (i = 0; i <= m; i++)
        count[i][0] = 0;
    for (j = 0; j <= n; j++)
        count[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if (a[i] == b[j])
                count[i][j] = count[i-1][j-1] + 1;
            else
                count[i][j] = max(count[i-1][j], count[i][j-1]);
        }
    }
    return count[m][n];
}

void backtrack(int c[M+1][N+1], char *a, char *b, int i, int j){
    if (i == 0 || j == 0)
        ;
    else if (a[i] == b[j]) {
        char temp = a[i];
        strcat(lcss, &temp);
        /* strcat(lcss, &a[i]); */
        backtrack(c, a, b, i - 1, j - 1);
    } else {
        if (c[i][j-1] > c[i-1][j])
            backtrack(c, a, b, i, j-1);
        else
            backtrack(c, a, b, i-1, j);
    }
}

int main() {
    char a[M+1] = {' ', 'a', 'b', 'c', 'b', 'd', 'a', 'b'};
    char b[N+1] = {' ', 'b', 'd', 'c', 'a', 'b', 'a'};
    int r, i;

    r = LCSLenth(a, b, M, N);
    printf("%d\n", r);

    backtrack(count, a, b, M, N);
    for(i = strlen(lcss) - 1; i >= 0; i--)
        printf("%c", lcss[i]);
    printf("\n");
}