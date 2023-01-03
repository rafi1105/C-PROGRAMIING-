#include<stdio.h>
struct node{
    int value;
    struct node *right;
    struct node *left;
};

struct node *newNode(int data){
    struct node *N= (struct node*)malloc(sizeof(struct node));
    N->value=data;
    N->left=NULL;
    N->right=NULL;

    return N;
}

void inOrderT(struct node *N){
    if(N->left!=NULL)
        inOrderT(N->left);
    printf("%d ",N->value);
    if(N->right!=NULL)
        inOrderT(N->right);
}

void preOrder ( struct node*N)
{
    printf ("%d ",N->value);
    if (N->left!=NULL)
    preOrder(N->left );
    if (N->right!=NULL)
    preOrder(N->right );
}
void postOrder ( struct node*N)
{
    
    if (N->left!=NULL)
    postOrder(N->left );
    if (N->right!=NULL)
    postOrder(N->right );
    printf ("%d ",N->value);
}


int main()
{

    struct node *root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    printf ("InOrder is -> \n");
    inOrderT(root);
    printf("\n");
    printf ("PreOrder is -> \n");
    preOrder(root);
    printf("\n");
    printf ("PostOrder is -> \n");
    postOrder(root);
    printf("\n");

    return 0;
}