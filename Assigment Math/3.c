/*Under certain conditions, cane sugar is converted into dextrose at a rate, which is proportional
to the amount unconverted at any time. If out of 60 grams of sugar at t = 0, 6 grams are converted
during the first 4 minutes, find the amount converted in 2 hours*/
#include <stdio.h>
#include <math.h>
int main()
{
    int M,m,t,t1,time;
    float Mass,e;
    double k,c;
printf("enter the mass of sugar in gm :");
scanf("%d",&M);
printf("enter the amount of during sugar in gm :");
scanf("%d",&m);
printf("enter %d sugar are during in :",m);
scanf("%d",&t);
k= 0.026340;
printf("the rate of sugar reduceing is : %lf \n",k);
printf(" after how many hours have you want to know the amount of sugar :");
scanf("%d",&t1);
time=t1*60;
c=exp(-k*time);
printf("%lf\n",c);
e=(float)(M-(M*c));
printf("the amount of sugar in 2 hours is : %f gm\n",e);


return 0;
}
