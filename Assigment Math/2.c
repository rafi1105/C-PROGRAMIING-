#include <stdio.h>
int main ()
{
    int t1,t2,time=3,t3,t;
    float rate,time1;
   //a pizza is removed from an oven, its temperature is measured at 350
 printf("Enter the temperature then the pizza is removed from an oven\n");
 scanf("%d",&t1);
 t2=150;
 rate=(float)(t1-t2)/time;
 printf(" the rate of time and temperature is : %f F/min\n",rate);
 printf(" enter the room temperature is :");
 scanf("%d",&t3);
 t=t2-t3;
 time1= (t/rate);
printf (" After %.2f min  the pizza temperature and the room temperature equal",time1);
}