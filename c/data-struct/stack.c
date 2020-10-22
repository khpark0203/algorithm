#include <stdio.h>

#define MAXSIZE 100

static int stack[MAXSIZE] = {0};
static int top = -1;

int push(int data)
{
    if (top < MAXSIZE - 1) {
        stack[++top] = data;
        return 0;
    } else {
        return -1;
    }
}

int pop(void)
{
    int ret = stack[top];
    stack[top] = 0;
    --top;
    return ret;
}

void display(void)
{
    int i = 0;
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main(void)
{
    while (push(4) == 0)
        ;

    pop();
    pop();
    pop();
    pop();
    pop();
    display();
}