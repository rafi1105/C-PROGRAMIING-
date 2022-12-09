#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node*pre;
    
}*head= NULL;
void insertbeg (int value);
void insertend (int value);
void any_possition_insert(int value);
void display();
int main ()
{
      option();
}
void insertbeg (int value)
{
  
  struct Node* newNode = (struct Node*)malloc (sizeof (struct Node));
  
  newNode->data = value;
  newNode->next=NULL;
  newNode->pre = NULL;
  if (head==NULL)
  {
    head = newNode;
  }
  else
  {
     newNode->next=head;
        head->pre=newNode;
        head=newNode;
  }
  printf ("\nInserted value at beginning");
  printf ("\n");
}
void insertend (int value)
{
  struct Node*temp;
  struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
  
  newNode->data = value;
  newNode->next=NULL;
  newNode->pre=NULL;
  if(head == NULL)
  {
    head = newNode;
   
  }
 else 
    {
        temp =head;
        while ( temp->next != NULL)
        {
            temp = temp->next;
        }
            temp -> next = newNode;
            newNode->pre = temp;    
    }
     printf("Inserted value at end");
    printf("\n");
}
void any_possition_insert(int value)
{
  struct Node *temp,*ptr;
  struct Node* newNode =(struct Node*) malloc (sizeof (struct Node));
  int loc,pos=1;
  newNode->data = value;
  newNode->next=NULL;
  if (head==NULL)
  {
    head = newNode;
   }
  else
  {
    
    printf("Please enter the position you want to insert: ");
    scanf(" %d", &loc);
    temp=head;
    if (loc==1)
    {
      newNode->next = temp;
      temp->pre=newNode;
      head=newNode;
    }
    else{
       while (pos<loc && temp->next != NULL)
    {
      pos++;
      ptr=temp;
      temp=temp->next;
      
    }
    ptr -> next = newNode;
    newNode->pre = ptr;
    newNode->next = temp;
    }
   
  }
   printf("Inserted value at %d position", loc);
    printf("\n");;

}
void display()
{
  printf ("\n~~~~ Display The List ~~~~~\n");
    struct Node *temp;
    if (head == NULL)
        printf("\n-> list is empty <-\n");
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
 option ();
}
void deletedbeg ()
{
  struct Node *temp;
  if (head == NULL)
  {
    printf("\n -> list emply <-");
  }
  else  
  {
    temp = head;
    head=temp -> next;
    printf("\n Delete First Node !\n");
  }
  
}



void option ()
{
  int choice,choice2,value, choice1;
  printf ("\n \n ****** MENU ****** \n 1. Insert \n 2. Delete \n 3. display \n 4. Search \n 5. Exit \n ");
   printf("Enter the option: ");
     scanf("%d",&choice1);
 switch (choice1)
     {
     case 1: // insertion order
      
              while (1)
    {
      printf("\n\n****Insertion*****\n\n 1. Insertion Beginning\n 2. Insertion End\n 3. Insertion Any Position\n 4. Go to Main Menu\n");
      printf("\n Enter the choice you want to Insertion : --> ");
      scanf("%d",&choice);
   printf("\n");
        switch (choice) // insertion
        {
            case 1:
                    printf("Enter Your Number to insertion : ");
                  scanf("%d",&value);
                  insertbeg (value);
            break;
            case 2: 
                   printf("Enter Your Number to insertion : ");
                  scanf("%d",&value);
                  insertend(value);
            break;
            case 3:
                   printf("Enter Your Number to insertion : ");
                  scanf("%d",&value);
                  any_possition_insert( value);
            break;
          
            case 4:
                  option();
                  break;
            default:
            printf("Invalid choice");
        }
    }
      break;
     case 2: // deletetion order
             while (1)
    {
      printf("\n\n****Delete*****\n\n 1. Deleted Beginning\n 2. Deleted End\n 3. Delete Any Position\n 4. Go To Main Menu\n");
      printf("\n Enter the choice you want to delete --> ");
      scanf("%d",&choice2);
   printf("\n");
        switch (choice2)
        {
            case 1:
                  deletedbeg ();
            break;
            case 2:
                //  deletedend();
            break;
            case 3:
               //  deleted_any();
            break;
          
            case 4:
                  option();
                  break;
            default:
            printf("Invalid choice");
        }
    }
      break;
     case 3: display();
      break;
     case 5: exit(0);
     default: printf("Invalid choice");
      break;
     }
}

