// Circular Queue implementation in C

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;
void option();
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}
int isEmpty() {
  if (front == -1) return 1;

  return 0;
}
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
  option();
}
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
      
    } 
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    option();
    return (element);
     
  }
  option();
}

void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
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
               enQueue(value);
                break;
            case 2:
                deQueue();
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
int main() {
  option();
  return 0;
}