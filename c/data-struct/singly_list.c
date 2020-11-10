#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* mknode(int val)
{
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->val  = val;
    node->next = NULL;

    return node;
}

void insnode(Node* root, Node* node)
{
    Node* n = root;
    while (n->next) {
        n = n->next;
    }
    n->next = node;
}

void display(Node* root)
{
    Node* n = root;
    if (!n) {
        printf("Nothing in list\n");
    } else {
        while (n) {
            printf("%d ", n->val);
            n = n->next;
        }
        printf("\n");
    }
}

void destory(Node** root)
{
    Node** n = root;
    Node* next = NULL;
    while (*n) {
        next = (*n)->next;
        free(*n);
        *n = next;
    }
}

int main(void)
{
    Node* root = mknode(1);
    insnode(root, mknode(3));
    insnode(root, mknode(9));
    insnode(root, mknode(11));
    insnode(root, mknode(200));
    display(root);
    destory(&root);
    display(root);
}