#include <stdio.h>
#include <math.h>
void main ()
{
 double population,population1,x,year,a,k,b;
 int percent;
 printf ("Enter the  Initial Population :\n");
scanf ("%lf",&population);
printf ("In 12 year how much percent increase the population - - -\n");
scanf ("%d",&percent);
x=(double)percent/100;
population1=population+(population*x);
printf ("After 12 years the population is : %lf \n\n",population1);
k=(log(population1/population))/12;
printf ("The rate of increasing population is : %lf\n",k);
printf("After how many years do you want to estimate the population ?\n");
scanf ("%lf",&year);
a=k*year;
b=population*exp (a);
printf ("After %.1f years the population is : %lf\t \n", year,b);
}