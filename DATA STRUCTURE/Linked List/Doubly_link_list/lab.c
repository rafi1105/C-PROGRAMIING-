#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
}*head= NULL;

void insertbeg (int value)
{
  struct Node* newNode = (struct Node*)malloc (sizeof (struct Node));
  newNode->pre=NULL;
  newNode->data = value;
  newNode->next=NULL;
  if (head==NULL)
  {
    head = newNode->pre;
  }
  else
  {
    newNode->next = head;
    head->pre = newNode;
    head= newNode;
  }
}
void display()
{
    struct Node *temp= (struct Node*) malloc(sizeof(struct Node));
    if (head == NULL)
        printf("list is empty");
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            printf(" DATA --> %d\n", temp->data);
            temp = temp->next;
        }
        printf(" DATA --> %d\n", temp->data);
    }
}
int main ()
{
    int value,choice,choice1,choice2;
  printf("Enter the choice: ");
  printf("\n");
    scanf("%d",&choice);
    printf("Enter Your Number: ");
      scanf("%d",&value);
    while (1)
    {
        switch (choice)
        {
            case 1:
            insertbeg (value);
            break;
            case 2:
            display();
            break;
      
            
            default:
            printf("Invalid choice");
        }
    }
}
