#include <stdio.h>
void abc ();
int main ()
{
    abc (); // abc calling 
    return 0;
}
void abc ()
{
    int a,b;
    scanf ("%d %d",&a,&b);
    printf ("%d",a+b);
}