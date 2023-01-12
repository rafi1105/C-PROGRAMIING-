//data structure lab
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int id;
    char name[20];
    int fisem; //first semester fee
    int sesem; //second semester fee
    struct node *nxt;
}node;
struct node *head=NULL;

void option();
void insert();
void popout();
void display();

void insert()
{
    node *n = malloc(sizeof(node));
    printf("Enter the Student id:");
    scanf("%d",&n->id);
    printf("Enter the Student name:");
    //gets(n->name);
    scanf("%[^/n]",n->name);
  //  fgets(n->name, MAX_CHAR, stdin); //input a name
    printf("Please pay your firt semester fee:");
    scanf("%d",&n->fisem);
    n->nxt=NULL;
    if(head==NULL)
    {
        head = n;
    }
    else
    {
        n->nxt=head;
        head=n;
    }
}

void popout()
{
    if(head==NULL)
    {
        printf("pop is not possible\n");
    }
    else
    {
        node *temp = head;
        head = temp->nxt;
    }
}

void display()
{
    node *temp = head;
    while (temp->nxt!= NULL)
    {
        printf("\n%d\n%d\n",temp->id, temp->name);
        temp= temp->nxt;
    }
    printf("\n%d\n",temp->id);
}
void option()
{
    int op;

    while (1)
    {
        printf("Menu: \n1.Insert\n2.Pop\n3.Display\n4.Exit\nPress your choice:");
        scanf("%d",&op);

        switch (op)
        {
            case 1:
                {
                    insert();
                }
            break;

            case 2: popout();
            break;

            case 3: display();
            break;

            case 4: exit(0);
            break;

            default: printf("Wrong Choice. Enter again\n");
            break;
        }

    }
}

int main()
{
    printf("\n\n\n\n");
    printf("\t\t~~ Welcome to student Database ~~\n\n");
    option();
}