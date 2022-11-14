#include <stdio.h>
#include <stdlib.h>
 
 struct Node 
 {
    int data;
    struct Node *next;
 } *head = NULL;

void insertAtBeginning (int value)
{
    struct Node * newNode = ( struct Node *) malloc (sizeof (struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else 
    {
        newNode->next = head;
        head = newNode;
    }
}
 void insertAtEnd (value)
 {
    struct Node *temp;
    struct Node *newNode = ( struct Node*) malloc (sizeof(struct Node));
    newNode->next = value;
    if (head == NULL)
    {
        newNode->next = NULL;
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
            newNode->next = NULL;
    }
 }
 void insertAtPosition (value)
 {
    
 }
 int main ()
 {
    int choice , value, choice1, loc,loc1;
    while (1)
    {
        mainMenu :
        printf ("\n \n ****** MENU ****** \n 1. Insert \n 2. Display \n 3. Generated size \n 4. Search \n 5. Exit \n ");
        scanf ("%d", &choice);
        switch (choice)
        {
        case 1:
                printf ( " Enter the value of the insert: ");
                scanf ("%d", &value);
            while (1)
            {
                printf (" which insertion do you want : \n");
                printf (" 1. Insert in the beginning \n 2. Insert in the end \n 3. Insert any specific  position \n");
                scanf ("%d", &choice1);
                switch (choice1)
                {
                    case 1: 
                    insertAtBeginning (value);
                    break;
                    case 2:
                    insertAtEnd (value);
                    break;
                    case 3: 
                    insertAtPosition (value);
                    default :
                    printf (" Wrong Input ");
                    goto mainMenu;
                }
                goto subMenuEnd;



            }
            subMenuEnd :
            break;
                case 2: 
                display ();
                break;
                case 3: 
                Generated_size ();
                break;
                case 4:
                search ();
                break;
                case 5: 
                exit (0);
        
        default:
        printf ( " Wrong Input");
            break;
        }
    }
 }