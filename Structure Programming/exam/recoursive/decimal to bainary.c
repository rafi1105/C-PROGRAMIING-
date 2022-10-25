#include <stdio.h>
int abc (int n);
int main()
{
   int num,f;
   scanf("%d", &num);
   f=abc(num);
   printf("%d\n",f);
}
int abc (int n)
{
   int f;
   if (n==0) 
   return 0;
   f=(n%2+10*abc (n/2));
   return f;
}