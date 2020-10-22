#include <stdio.h>

void qsort(int data[], int left, int right)
{
    int l = left;
    int r = right;
    int mid = (l + r) / 2;
    int pivot = data[mid];

    while (l <= r) {
        while (data[l] < pivot) {
            ++l;
        }

        while (data[r] > pivot) {
            --r;
        }

        if (l <= r) {
            if (l != r) {
                int tmp = data[l];
                data[l] = data[r];
                data[r] = tmp;
            }
            ++l;
            --r;
        }
    }
    if (l < right) {
        qsort(data, l, right);
    }
    if (left < r) {
        qsort(data, left, r);
    }
}

int main(void)
{
    int data[] = {1, 4, 5, 6, 2, 3, 1, 1, 7, 8, 10, 14, 13, 15, 20, 21, 22, 23, 50, 41};
    int len = sizeof(data) / sizeof(data[0]);
    int i = 0;

    qsort(data, 0, len - 1);

    for (i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}