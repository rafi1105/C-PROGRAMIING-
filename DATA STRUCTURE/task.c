#include <stdio.h>
struct node {
    int value;
    struct node*left, *right;
};

struct node *newNode (int value)
{
    struct node*N =(struct node*)malloc(sizeof(struct node));
    N->value = data;
    N->left = NULL;
    N->right = NULL;
    return N;
}

void  inorder (struct node  *N)
{
    if (N->left != NULL)
    inorder(N->left);
    printf(" %d", N->value);
    if (N->right != NULL)
    inorder(N-> right);
}

int main ()
{
    struct node*root =newNode(1);
    
}