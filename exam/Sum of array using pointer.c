#include <stdio.h>
int main ()
{
  int *p,a[20],sum=0,n,i;
  printf("enter the number of elements");
  scanf("%d",&n);
  printf("\n");
  for (i=0;i<n;i++) // input
  {
    scanf("%d",&a[i]);
  }
p=&a[0];
for (i=0;i<n;i++){
   sum=sum+(*p);
   p++;
}
printf("\n");
printf ("%d",sum);
  
  
  
    return 0;
}
