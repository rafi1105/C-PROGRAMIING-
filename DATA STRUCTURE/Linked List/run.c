#include<stdio.h>
#include<stdlib.h> 

struct Node 
{
    int data;
    struct Node *next;
};
void traverse ( struct Node*ptr)
{
    while ( ptr != NULL )
    {
        printf (" element -> %d\n", ptr->data );
        ptr = ptr-> next;
    }
}
int main ()
{ 
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head= (struct Node*) malloc (sizeof (struct Node));
    second = (struct Node*) malloc (sizeof (struct Node));
    third= ( struct Node*) malloc (sizeof (struct Node));

    head -> data = 45;
    head -> next= second;
    second -> data =54;
    second -> next = third;
    third -> data =43;
    third -> next =NULL;

    traverse (head);
}