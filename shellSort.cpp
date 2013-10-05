#include<iostream>
#include<stdlib.h>
using namespace std;

#define LLEN 12
#define DLLEN 3

void shellInsert(int l[13], int dk) {
    int i, j;

    for (i = dk + 1; i <= 12; i++) {
        if (l[i] < l[i - dk]) {
            l[0] = l[i];
            // for (j = i - dk; j > 0 && l[0] < l[j + dk]; j -= dk) {
            for (j = i - dk; j > 0 && l[0] < l[j]; j -= dk) {
                l[j + dk] = l[j];
            }
            l[j + dk] = l[0];
        }
    }

    // cout << "\n" << dk << endl;
    // for (int k = 1; k < 13; k++)
    //     printf("%d ", l[k]);
    // cout << "\n";
}

void shellSort(int l[13], int dlta[DLLEN]) {
    for (int i = 0; i < DLLEN; i++)
        shellInsert(l, dlta[i]);
}

int main() {
    int l[13];
    int dlta[DLLEN] = {5, 3, 1};

    for (int i = 0; i < 12; i++) {
        scanf("%d", &l[i + 1]);
    }

    shellSort(l, dlta);

    cout << "\n";
    for (int j = 1; j < LLEN + 1; j++)
        printf("%d ", l[j]);
    cout << "\n";
}

/*
1
3413
51
3
51
23
5
146
346
23
46
2463

5
1 5 51 3 23 23 2463 146 346 51 46 3413 

3
1 5 23 3 23 51 51 46 346 2463 146 3413 

1
1 3 5 23 23 46 51 51 146 346 2463 3413 

1 3 5 23 23 46 51 51 146 346 2463 3413

 */