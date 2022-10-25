#include <stdio.h>

int abc(char str[] , int i);
int main ()
{
    char str[100];
    int l=0;
    scanf("%[^\n]",str);
    l=abc(str,0);
    printf("%d\n",l);
    return 0;
}
int abc(char str[] , int i)
{
   int l;
    if (str[i]=='\0')
    return i;
l=abc(str,i+1);
    return l;
}