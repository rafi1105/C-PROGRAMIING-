#include <stdio.h>
#include <math.h>
int main()
{
    float k, Ta=75, T=350, c, t=3;

    printf("\n\nWe know That,\ndT/dt = -k(T - Ta)\n");
    printf("\n\nGiven That,\n");
    printf("Ta = %.0fF\nT = %.0fF\nC = ?\n",Ta, T);
    printf("\nWhen t = 0 min,\n");    
    c=T-Ta;
    printf("C = (T - Ta)\n\nSo, C = %.0fF",c);
    printf("\n\nWhen t = 3 min, T=150 F\n\n");
    T=150;
    k=-(log((T-Ta)/c))/t;
    printf("Hence,k=-[ln{(T-Ta)/c}]/t\n\n\nSo, k = %f min",k);
    printf("\n\n\n");

    return 0;
}
