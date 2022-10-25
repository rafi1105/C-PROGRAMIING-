#include <stdio.h>
void abc(int *a,int *b)
{
    int *a,*b;
    *a=*a+10;
    *b=*b+10;
    printf("%d, %d\n",*a,*b);
}
int main()
{
    int a=10,b=20;
    abc(&a,&b);
    printf("%d, %d\n",a,b);
    return 0;

}