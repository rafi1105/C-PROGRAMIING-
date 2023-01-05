#include <stdio.h>
#include <stdlib.h>
int queue[5];
int front = -1;
int rear = -1;
void option();
void enqueue(int value);
void dequeue();
void display();
void exit();
int main()
{
    option();
}
void enqueue(int value)
{
    if (front == -1)
    {
        front++;
        rear++;
        queue[rear]=value;
        printf("EnQueue completed -> %d ",value);
    }
    else if (rear == 5)
    {
        printf("\n Queue is full \n");
    }
    else if (rear !=5)
    {
        rear++;
        queue[rear]=value;
        printf("EnQueue completed -> %d ",value);
    }
    option();
}
void dequeue()
{
    if (front == rear)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("DeQueue completed -> %d ",queue[front]);
        front++;
        printf(" front is : %d", front);
        if (front == 6)
        {
            front = 0;
          //  rear = -1;
        }
      
    }
    option();
}
void display() 
{
    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        if (front <= rear )
        {
            printf("Queue is not empty \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
        }
        else if (rear <= front){
            printf("\nQueue circular \n");
        }
}
option();
}
void size()

{
    int size = 0;
    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        size++;
        printf(" Queue size = %d \n",size);
    }
    option();
}
void option()
{
    int value,ch;
    printf("\n");
    printf ("****** Queue Project ******");
    printf("\n---------------------------------------\n");
    printf("\n 1. EnQueue\n 2. DeQueue\n 3. Display\n 4. Size\n 5. Exit\n\n");
    printf("---------------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the value : ");
                scanf("%d",&value);
               enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4: 
            size();
              break;
            case 5:
                exit(0);
                break;
                default:
                printf("Wrong choice");
                option ();
                break;
        }
}
