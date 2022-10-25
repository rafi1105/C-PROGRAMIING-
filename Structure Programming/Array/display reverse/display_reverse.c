#include <stdio.h>
int main()
{
    int a[50],n,i,j=0,b[100];
    printf("enter the number of elements in the array : \n");
    scanf("%d",&n);
    // input the array values
    for (i=0; i<n; i++)
    {
        printf("enter the number %d  : ", i+1);
        scanf("%d",&a[i]);
    }
    //reverse the array values
    printf(" the reverse of the array values :\n");
    for (i=n; i>=0; i--)
    {
        for(j=0; ; j++)
        a[i]=b[j];
    }
    for (j=0; j<n; j++)
    
    
    {
        printf("%d ", b[j]);
    }



return 0;
}
