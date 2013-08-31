#include<stdio.h>

void swap(int a[], int x, int y);
void qsort(int a[], int left, int right);

void swap(int a[], int x, int y) {
	int temp;
	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
void qsort(int a[], int left, int right) {
	int last;

	if (left >= right) {
		return ;
	}

	last = left;
	swap(a, left, (left + right)/2);
	for (int i = left + 1; i <= right; ++i)
		if (a[i] < a[left])
			swap(a, ++last, i);
	swap(a, left, last);

	qsort(a, left, last - 1);
	qsort(a, last + 1, right);
}

main() {
	int a[] = {80, 2, 6, 20, 42, 3, -1, 10};
	int length;

	length = sizeof a / sizeof a[0];
	qsort(a, 0, length - 1);

	for (int i = 0; i < length; ++i)
		printf("%d\n", a[i]);
}
