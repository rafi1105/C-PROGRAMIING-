#include <stdio.h>
int abc (int n);
int main ()
{
    int n,sum;
    scanf("%d", &n);
    sum=abc (n);
    printf("%d\n",sum);
    return 0;
}
int abc (int n)
{
    int sum;
    if (n==0)
    return 0;
    sum=n+abc(n-1);
    return sum;

}