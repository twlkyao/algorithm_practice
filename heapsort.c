#include<stdio.h>

void swap(int *a, int *b);
void ArrRpout(int heap[], int hpLength);
void HeapAdjust(int heap[], int s, int m);
void HeapSort(int heap[], int hpLength);

int main() {
    int heap[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; /* heap[0] is neglect */
    int hpLength = sizeof(heap) / sizeof(heap[0]);

    HeapSort(heap, hpLength - 1);
    ArrRpout(heap, hpLength - 1);
}

void HeapAdjust(int heap[], int s, int m) {
    int j;
    int rc = heap[s];

    for (j = 2 * s; j <= m; j *= 2) {
        if (j < m && heap[j] < heap[j + 1])
            ++j;
        if (rc >= heap[j])
            break;
        heap[s] = heap[j];
        s = j;
    }
    heap[s] = rc;
}

void HeapSort(int heap[], int hpLength) {
    int i;

    for (int i = hpLength / 2; i > 0; --i)
        HeapAdjust(heap, i, hpLength);
    for (int i = hpLength; i > 1; --i) {
        swap(&heap[1], &heap[i]);
        HeapAdjust(heap, 1, i - 1);
    }
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void ArrRpout(int heap[], int hpLength) {
    for (int i = hpLength; i > 0; --i) {
        printf("%d\n", heap[i]);
    }
}