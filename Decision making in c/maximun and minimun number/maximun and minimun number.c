#include <stdio.h>
int main()
{
    int a,b,c;
    printf("enter the first number :");
    scanf("%d",&a);
    printf("enter the second number :");
    scanf("%d",&b);
    printf("enter the third number :");
    scanf("%d",&c);
    if(a>b&&a>c)
    {
        printf ("maximum number is : %d ",a);
    }
    else if (b>c&&b>a)
    {
        printf ("maximum number is : %d ",b);
    }
    else if (c>a&&c>b)
    {
        printf ("maximum number is : %d ",c);
    }
    printf("\n");
    if(a<b&&a<c)
    {
        printf ("minimum number is : %d ",a);
    }
    else if (b<c&&b<a)
    {
        printf ("minimum number is : %d ",b);
    }
    else if (c<a&&c<b)
    {
        printf ("minimum number is : %d ",c);
    }

return 0;
}
