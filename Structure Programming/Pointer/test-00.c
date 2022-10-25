#include <stdio.h>
void swap (int a,int b);
int main()
{
    int x=2,y=20;
    swap ( & x, & y);
    printf ("the value of x is : %d \n the value of y is: %d \n",x,y);


}
void swap (int a, int b)
{
    int temp=0;
    temp=a;
    a=0;
    a=b;
    b=temp;
 printf ("the value of a is : %d \n the value of b is: %d \n",a,b);
}
