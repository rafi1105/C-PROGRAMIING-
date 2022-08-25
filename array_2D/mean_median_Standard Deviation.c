#include <stdio.h>
#include <math.h>
int main()
{
    int n,a[20],meadian,sum=0,i,meadian1,b,mean,x;
    float f,sd;
    printf("\t which values you want to calculate \t \n");
    printf("1. Mean values \n 2. Median values \n 3.standard deviation values \n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    {
        printf("enter the number of elements");
        scanf("%d",&x);
     //meadian
    if(x%2!=0)
    {
        meadian=(x/2)+1;
        printf("%d",meadian);
    }
    else if(x%2==0)
    {
         meadian=x/2;
        printf("%d",meadian);
        meadian1=(meadian+1);
        printf("%d",meadian1);
    }
    }
    break;
    case 2:
    {
    //mean
    printf("enter the number of element of x :");
    scanf("%d",&x);
    printf("Input all the values of x :");
    for(i=0;i<x;i++)
    {
        scanf("%d",&a[i]);
          sum=sum+a[i];
    }
    f=(float)sum/x;
    printf("mean values is : %f",f);
    }
    break;
    //standard deviation
    case 3:
    {
        printf("How many numbers:");
 scanf("%d", &n);
 printf ("Enter numbers: ");
 for(i = 0; i<n; i++)
 {
 scanf("%f", &a[i]);
 }
        sum= 0;
 for(i = 0; i < n; i++)
 {
   sum+= (a[i] - mean) * (a[i] - mean);
   sd = sqrt(sum / n);
   
   printf("Standard Deviation: %f\n", sd);
    }

    }
    break;
    }
return 0;
}
