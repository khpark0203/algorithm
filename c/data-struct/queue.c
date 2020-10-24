#include <stdio.h>
#include <string.h>

int queue[10000];
int pos = -1;

void push(int val)
{
    queue[++pos] = val;
}

int pop(void)
{
    int ret = queue[0];
    memmove(&queue[0], &queue[1], sizeof(queue) - sizeof(int));
    --pos;
    return ret;
}

void display(void)
{
    int i = 0;
    for (i = 0; i <= pos; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(void)
{
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    pop();
    pop();
    pop();
    display();
}