#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};
int main ()
{
    struct node * head,*temp;
    struct node * fnode;
    int n;
    scanf ("%d",&n);
    head = NULL;
     for ( int i=0; i < n; i++ )
    fnode =(struct Node*) malloc (sizeof(struct node));
    printf ( " enter the number of data nodes\n" );
    scanf("%d", & fnode -> data );
    fnode -> next = NULL;
    if ( head == NULL )
    head=temp= fnode;
    else 
      
        {
        temp -> next = fnode;
        temp= fnode;
        }

        

    }

