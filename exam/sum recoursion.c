#include <stdio.h>
int sum (int n);
int main()
{
    int n,f;
    scanf("%d",&n);
    f=sum(n);
    printf("%d\n",f);
    return 0;
}
int sum (int n)
{
    int f;
    if (n==0)
    return 0;
    f=n+sum(n-1);
    return f;
}