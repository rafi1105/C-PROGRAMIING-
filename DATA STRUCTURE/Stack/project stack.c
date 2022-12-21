#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void option();
void push(int value);
void pop();
void peek();
void display();
int main()
{
    option();
}
void option()
{
     int ch,value;
     while (1)
    {
     printf( "\n 1. Push\n 2. Pop\n 3. peek\n 4. Display\n 5. Exit\n");
    printf ("Enter your choice: ");
    scanf("%d", &ch);
    printf ("\n");
    
        switch (ch)
        {
        case 1:
        {
            printf ("Enter your value -> ");
            scanf("%d", &value);
            push(value);
        }
            break;
       case 2:
        {
           // peek();
            pop();
        }
        break;
        
        case 3:
            peek();
        break;
        
        case 4: 
            display();
        break;
        
        case 5: exit(0);
        break;
        default:
         printf ("Invalid option enter 1 -> 5 ");
            break;
        }
    }
}
void push (int value)
{
    struct Node *newnode =(struct Node*) malloc (sizeof(struct Node));
    struct Node *temp;
    temp=head;
    newnode->data = value;
    newnode->next = NULL;
    if(head==NULL)
    {
        head=newnode;
         printf(" push node-> %d\n",newnode->data);
    }
    else 
    {
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        
       temp->next = newnode;
       
        printf(" push node-> %d\n",newnode->data);
    }
     option ();
    }
void pop()
{
    struct Node* temp,*ptr;
    temp = head;
    if (head==NULL)
    {
        printf ("stack is empty");
    }
    if (temp->next==NULL) {
        head=NULL;
        printf("Now stack is empty");
    }
    else 
    {
        while (temp ->next != NULL)
        {
            ptr=temp;
            temp=temp-> next;
        }
        printf("Pop Number is -> %d", temp->data);
        ptr->next=NULL;
    }
     option ();
}
void display()
{
    struct Node *temp;
    temp=head;
    if (head==NULL)
    {
        printf ("\n stack is empty\n");

    }

    else {
        while (temp->next !=NULL)
        {
            printf("list is -> %d\n", temp->data);
            temp=temp-> next;
        }
        printf("list is -> %d\n", temp->data);
        
    }
}
void peek ()
{
    struct Node*temp=head;
    if (head==NULL)
    {
        printf(" empty stack\n");
    }
    else 
    {
        while (temp ->next != NULL)
        {
            temp = temp-> next;
        }
        printf ("Peek Number is -> %d", temp->data);
    }

     option ();
}
