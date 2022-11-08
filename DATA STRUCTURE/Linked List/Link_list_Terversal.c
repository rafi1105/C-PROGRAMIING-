#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node*next;
};
 void Link_list_travarse (struct Node*ptr)
{
    
    while (ptr != NULL)
    {
        printf ("element is -> %d \n " , ptr -> data );
        ptr = ptr->next;
    }
}
int main ()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;

        // Allocate memory for nodes in the  linked list heap
        head = ( struct Node * ) malloc ( sizeof (struct Node ) );
        second = ( struct Node * ) malloc ( sizeof(struct Node ) );
        third = ( struct Node * ) malloc ( sizeof(struct Node ) );
        // link -> 1
        head -> data = 5;
        head -> next = second;
        // link -> 2
        second -> data =3;
        second -> next = third;
        // link -> 3
        third -> data = -21 ;
        third -> next = NULL;
        Link_list_travarse(head);
        return 0; 
}
