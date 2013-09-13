#include <stdio.h>

void merge(int numbers[], int temp[], int left, int mid, int right)
{
    int i, left_end, tmp_pos, n_length;

    left_end = mid - 1;
    tmp_pos = left;
    n_length = right - left + 1;

    while ((left <= left_end) && (mid <= right)) {
        if (numbers[left] <= numbers[mid])
            temp[tmp_pos++] = numbers[left++];
        else
            temp[tmp_pos++] = numbers[mid++];
    }

    while (left <= left_end)
        temp[tmp_pos++] = numbers[left++];

    while (mid <= right)
        temp[tmp_pos++] = numbers[mid++];

    for (i = 0; i <= n_length; i++, right--)
        numbers[right] = temp[right];
}

void m_sort(int numbers[], int temp[], int left, int right)
{
    int mid;

    if (right > left)
    {
        mid = (right + left) / 2;

        m_sort(numbers, temp, left, mid);
        m_sort(numbers, temp, mid+1, right);
        merge(numbers, temp, left, mid+1, right);
    }
}

void mergeSort(int numbers[], int temp[], int array_size)
{
    m_sort(numbers, temp, 0, array_size - 1);
}

void m_print(int m_arr[], int length) {
    for (int i = 0; i <= length - 1; ++i) {
        printf("%5d", m_arr[i]);
    }
    printf("\n");
}

#define ARR_SIZE 7

int main()
{
    int a[ARR_SIZE] = {1, -9, 6, 5, 102, 9, 2};
    int tmp[ARR_SIZE] = {};

    m_print(a, sizeof(a) / sizeof(a[0]));

    mergeSort(a, tmp, ARR_SIZE);

    m_print(a, sizeof(a) / sizeof(a[0]));

    return 0;
}
