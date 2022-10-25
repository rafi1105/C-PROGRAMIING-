// delete a element in array
#include <stdio.h>
int main ()
{
    int a[100];
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    printf ("Enter the deleted point :");
    scanf("%d",&j); // 2
    for (i=j-1;i<n;i++)
    {
       a[i]=a[j];
       j++;

    }
   for(i=0;i<n-1;i++)
   {
    printf (" Now element are :%d\n",a[i]);
   }
  
}