#include <stdio.h>
int main()
{
   float marks[3];
printf("enter the 3 prices:");
scanf("%f %f %f", &marks[0],&marks[1],&marks[2]);
printf(" item 1 price with gst:%f\n", marks[0]+(marks[0]*0.18));
printf(" item 2 price with gst:%f\n", marks[1]+(marks[1]*0.18));
printf(" item 3 price with gst:%f\n", marks[2]+(marks[2]*0.18));
printf(" Total price with gst:%.2f \n", ((marks[0]+(marks[0]*0.18))+(marks[1]+(marks[1]*0.18))+(marks[2]+(marks[2]*0.18))));
    return 0;

}