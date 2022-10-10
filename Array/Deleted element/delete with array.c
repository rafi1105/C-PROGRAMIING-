#include <stdio.h>
int main ()
{
    int a[5]={1,2,3,4,5};
    int i,j;
    printf ("Enter the deleted point :");
    scanf("%d",&j);
    for (i=j-1;i<5;i++)
    {
       a[i]=a[j];
       j++;

    }
   for(i=0;i<5-1;i++)
   {
    printf (" Now element are :%d\n",a[i]);
   }
  
}