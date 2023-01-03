#include <stdio.h>
#include <stdlib.h>
 struct node
 {
    int key;
    struct node *left *right;
 };
 struct node *temp= (struct node*)malloc (sizeof(struct node));
 temp->key =item;
 temp -> left = temp -> right =NULL;
  
  void inorder(struct node * root)
  {
    if (root != NULL)
    {
        inorder (root -> left);
        printf ("%d \n ",root -> key);
        inorder (root -> right);
    }
  }

struct node * insert(struct node * node, int key)
{
   if (node == NULL)
   return newNode(key);
   if (key < node->key)
   node 
}

