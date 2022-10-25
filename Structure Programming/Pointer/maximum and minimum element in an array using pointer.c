#include<stdio.h>
int abc(int n,int *a)
{
    int i,min;
    min= *(a+1);
    for(i=0;i<n;i++)
    {
        if (min>*(a+i))
           min= *(a+i);
    }
    return min;
}
int findmax(int n,int *a)
{
    int i,max;
    max=*(a+1);
    for(i=0;i<n;i++)
    {
        if(max<*(a+i))
           max=*(a+i);
    }
    return max;
}
int main()
{
    int n,*a,i,min,max;
    printf("Enter the size of array ");
    scanf("%d",&n);
    printf("Enter the elements ");
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    min=abc(n,a);
    max=findmax(n,a);
    printf("Minimum element in the array is %d\n",min);
    printf("maximum element in the array is %d",max);
    return 0;
}