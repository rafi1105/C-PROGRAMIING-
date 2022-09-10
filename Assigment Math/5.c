
#include <stdio.h>
#include <math.h>
int main()
{
    int M,m,t,t1,time;
    float Mass,e;
    double k,c;
printf("enter the mass of uncovertable mango in gm :");
scanf("%d",&M);
printf("enter the amount of covert mango juice during in gm :");
scanf("%d",&m);
printf("enter time mango juice are during in:");
scanf("%d",&t);
k= 0.026340;
printf("the rate of mango juice reduceing is : %lf \n",k);
printf(" after how many hours have you want to know the amount of mango juice :");
scanf("%d",&t1);
time=t1*60;
c=exp(-k*time);
printf("%lf\n",c);
e=(float)(M-(M*c));
printf("the amount of mango juice in 2 hours is : %f gm\n",e);
return 0;
}
