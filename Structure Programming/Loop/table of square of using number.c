#include <stdio.h>
int main ()
{
  int n, i;
  scanf("%d",&n);
  i=1;
while (i<=n)
{
    printf ("%10d %10d \n",i,i*i);
    i++;
}  
    return 0;
}
