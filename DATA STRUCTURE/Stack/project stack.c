#include <stdio.h>
#include <stdlib.h>
struct Node { 
    int data;
    struct Node *next;
}*head=NULL;
void option();
int empty ()
{
    if (head==NULL)
    {
        printf("\n the stack is empty\n");
        return 1;
    }
    else if (head !=NULL)
    {
        return 0;
    }
}
int push (int value)
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
       newnode->next = head;
       head=newnode;
        printf(" push node-> %d\n",newnode->data);
    }
     option ();
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
void pop ()
{
    struct Node* temp,*ptr;
    temp = head;
    if (!empty())
    {
        empty();
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
void show()
{
   struct Node* temp;
   temp = head;
   if (head == NULL)
   {
    printf(" empty stack\n");
   }
   else if(temp->next= NULL)
 printf("\n list of the stack is ->%d \n", temp->data);
   else 
   {
         while (temp->next  != NULL)
   {
    printf("\n list of the stack is ->%d \n", temp->data);
    temp = temp->next;
   }
   }
  
    option ();
}
void option()
{
     int ch,value;
    printf ("Enter your choice: ");
    scanf("%d", &ch);
    printf ("\n");
    while (1)
    {
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
            show();
        break;
        case 5: exit(0);
        break;
        default:
         printf ("Invalid option enter 1 -> 5 ");
            break;
        }
    }
}
int main ()
{
    option ();
}