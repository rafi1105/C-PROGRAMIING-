#include <stdio.h>
#include <stdlib.h>

int stack[6];

int font=-1;
void option();
void push(int value);
void pop();
void display();
void peek();   
int main()
{
    option();
}
void option()
{
    int value,ch;
    printf("\n");
    printf("---------------------------------------\n");
    printf(" 1. Push\n 2. Pop\n 3. Display\n 4. Peek\n 5. exit\n");
    printf("---------------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the value : ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
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
void push(int value)
{
    if (font == 6)
    {
        printf("Stack Overflow");
            }
    else
    {
        font++;
        stack[font] = value;
        
    }
printf( "Push compled\n");
option();
}
void pop()
{
    if (font == -1)
    {
        printf("Stack Underflow");
            }
    else
    {
        font--;
}
printf( "Pop compled\n");
option();
}
void display()
{ 
    if (font == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf ("Stack list -> \t");
        int i;
        for (i = 0; i <= font; i++)
        {
            printf("%d\t",stack[i]);
        }
    }
    option();
printf("\n");
}
void peek()
{
    if (font == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Peek element is -> %d\t\n", stack[font]);
}
option();
printf("\n");
}
