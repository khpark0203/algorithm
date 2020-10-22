#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibo[1000000];

int fibo_recur(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    int ret = fibo_recur(n - 1) + fibo_recur(n - 2);
    return ret;
}

int fibo_dp(int n)
{
    if (fibo[n] == -1) {
        fibo[n] = fibo_dp(n - 1) + fibo_dp(n - 2);
    }
    return fibo[n];
}

int fibo_loop(int n)
{
    int a = 0;
    int b = 1;
    int c = 0;
    int i = 0;
    for (i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return a;
}

int main(void)
{
    int n = 10;

    memset(fibo, -1, sizeof(fibo));
    fibo[0] = 0;
    fibo[1] = 1;

    printf("Recursive %d\n", fibo_recur(n));
    printf("Dynamic1  %d\n", fibo_dp(n));
    printf("Loop      %d\n", fibo_loop(n));
}