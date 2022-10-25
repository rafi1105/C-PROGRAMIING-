
#include <stdio.h>
struct number
{
    int arr[20];
    int i,j,s; 
}su;

int main()
{
    
    scanf("%d", &su.i);
    for ( int j=0; j<su.i; j++)
    {
        scanf("%d", &su.arr[j]);
        s=0;
        s=su.arr[j]+s;
    }
    printf("%d",su.s);

}