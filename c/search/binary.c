#include <stdio.h>

#define LEN 1000000

int main()
{
    int given[LEN] = {0};
    int target = 3000123;

    for (int i = 0; i < LEN; i++) {
        given[i] = i + 1;
    }

    int left, right, mid;
    left = 0;
    right = LEN - 1;

    while (1) {
        mid = (left + right) / 2;
        if (target > given[mid]) {
            left = mid + 1;
        } else if (target < given[mid]) {
            right = mid - 1;
        } else {
            break;
        }

        if ((right - left) < 0) {
            mid = -1;
            break;
        }
    }

    if (mid != -1) {
        printf("given[%d] = %d\n", mid, given[mid]);
    } else {
        printf("There is no %d\n", target);
    }
}