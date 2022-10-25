#include <stdio.h>
void abc(int a,int b)
{
    a=a+10;
    b=b+10;
    printf ("%d, %d \n",a,b);
}
int main()
{
    int a,b;
    a=10;
    b=20;
    abc (a,b);
    printf ("%d ,%d",a,b);
    return 0;

}