#include <stdio.h>
int abc (int a,int b);
int main ()
{

    int c,a,b;
    printf("enter the number is :");
    scanf("%d %d";&a,&b);
    c=abc (a,b);
    printf("sum is : %d",c);
    return 0;
}
int abc (int a,int b)
{
    int c;
    c=a+b;
    return c;
}
