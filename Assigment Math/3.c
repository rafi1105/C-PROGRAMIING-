
#include <stdio.h>
#include <math.h>
int main()
{
    int M,m,t,t1,time;
    float Mass,e;
    double k,c;
printf("enter the mass of uncovertable sugar in gm :");
scanf("%d",&M);
printf("enter the amount of covert sugar during in gm :");
scanf("%d",&m);
printf("enter time sugar are during in:");
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
