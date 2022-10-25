#include <stdio.h>
int abc();
int main ()
{
int c;
c=abc(); //calling function
printf("%d",c);

return 0;
}

int abc()
{
    int a,b;
    scanf ("%d %d",&a,&b);

   return a+b;
}
