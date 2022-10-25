#include<stdio.h>
int main ()
{
   int  a[]={1,10,5,4},*p;
    p=&a[0];
    p=p+2;
    for(int i=0;i<=2;i++)
    printf("%d\n",(*p)--); 
    // if *p-- then print 5,10,1 or *p-- then print the 3 memory address.
}