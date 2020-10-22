#include <stdio.h>

int max(int a, int b)
{
    int ret = (a > b) ? a : b;
    return ret;
}

int main(void)
{
    int data[] = {-1, -9, 1, 2, 3, 4, 5, -1, -10, 14};
    int len = sizeof(data) / sizeof(data[0]);
    int i = 0;
    int maxsum = 0;
    int maxnum = 0;

    for (i = 0; i < len; i++) {
        maxsum = max(data[i], data[i] + maxsum);
        maxnum = max(maxsum, maxnum);
    }

    printf("%d\n", maxnum);
}