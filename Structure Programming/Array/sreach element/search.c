#include<stdio.h>
int main ()
{
    int a[30],i,j,n,p,flag=0;
    scanf("%d",&n);
    printf("enter the number of elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf(" enter the number which you want sreach ?\n");
    scanf("%d",&p);
    for (i=0;i<n;i++)
    {
        if (a[i]==p)
            printf ("yes the number is available : \n%d",a[i]); 
            flag++;
    }
    if (flag==0)
    {
        printf("no the number is available : \n");
    }
    
}
