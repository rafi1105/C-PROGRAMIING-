#include<stdio.h>
int main ()
{
   int  a[]={1,10,5,4},*p;
    p=&a[0];
    p=p+2;
    for(int i=0;i<=2;i++)
    printf("%d\n",(*p)--);
}