/* Find the k-th smallest element of an array using partition of quicksort method. */

#include<stdio.h>
#include<stdlib.h>

swap_array(int *a, int p, int q) {
    int temp;
    temp = a[p];
    a[p] = a[q];
    a[q] = temp;
}

qsort_divide(int *a, int start, int end) {
    int i, last, pivot;
    pivot = (start + end) / 2;

    last = start;
    swap_array(a, start, pivot);
    for (i = start + 1; i <= end; i++ ) {
        if (a[i] < a[start]) {
            swap_array(a, ++last, i);
        }
    }
    swap_array(a, start, last);

    return last;
}

randomized_select(int *a, int start, int end, int k) {
    int q, i;
    /* printf("start: %d\n", start); */

    if (start == end)
        return a[start];

    q = qsort_divide(a, start, end);
    i = q - start + 1;

    if (k == i)
        return a[q];
    else if (k < i)
        return randomized_select(a, start, q - 1, k);
    else
        return randomized_select(a, q + 1, end, k - i);
}

int main(int argc, char *argv[]) {
    int a[] = {3, 5, 9, 12, 23, 231, 0, 67, 2};
    int k = 4;
    int end = sizeof a / sizeof a[0];
    int result;

    k = atoi(argv[1]);
    if (k > 0) {

        result = randomized_select(a, 0, end - 1, k);
        printf("result: %d\n", result);

        for (int i = 0; i < end; i++) {
            printf("%d\n", a[i]);
        }
    } else
        printf("error\n");

}