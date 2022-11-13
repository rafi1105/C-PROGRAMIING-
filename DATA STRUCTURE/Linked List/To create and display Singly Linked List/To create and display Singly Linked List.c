#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;                        //Data of the node
    struct node *next;           //Address of the next node
}*head;

void createNodeList(int n); // function to create the list
void displayList();         // function to display the list

int main()
{
    int n;
		printf("\n\n Linked List : To create and display Singly Linked List :\n");
		printf("-------------------------------------------------------------\n");
		
    printf(" Input the databer of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list : \n");
    displayList();
    return 0;
}
void createNodeList(int n)
{
    struct node *newNode, *tmp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL) //check whether the newNode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard
        
       printf(" Input data for node 1 : ");
        scanf("%d", &head -> data);
       // head->data = data;      
        head->next = NULL; // links the address field to NULL
        tmp = head; 
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &newNode ->data);
 
               // newNode->data = data;      // links the data field of newNode with data
                newNode->next = NULL; // links the address field of newNode with NULL
 
                tmp->next = newNode; // links previous node i.e. tmp to the newNode
                tmp = tmp->next; 
            }
        }
    }
}
void displayList()
{
    struct node *tmp;
    if(head == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->data);       // prints the data of current node
            tmp = tmp->next;                     // advances the position of current node
        }
    }
} 