#include <stdio.h>
int main()
{
    int a[10],n,i, j,p,cp,temp;
    printf ("enter the number of elements: ");
    scanf("%d",&n); 
    // input array
    for(i=0;i<n;i++)
    {
        scanf (" %d",&a[i]);
    }
    printf ("Enter the possition you want to add :");
    scanf("%d",&p); //3
    printf("what is the value");
    scanf("%d",&cp); //6
    for(i=n;i>p-1;i--)
    {
       a[i]=a[i-1];
       
    }
     a[p-1]=cp;
     printf("new array is :");
    for(i=0;i<n+1;i++)
    
    printf ("%d\n",a[i]);
    
}