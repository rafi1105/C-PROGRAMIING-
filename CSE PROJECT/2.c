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
int abc(char [] , int i)
{
    if (str[i]=='\0')
    return i;
    return abc(str,i+1);
}