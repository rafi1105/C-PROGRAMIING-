//. Write a C program to print all alphabets from a to z
#include <stdio.h>
void main()
{
    char n;
    printf("enter the first alphabet :");
    scanf("%c",&n);
   
    while (n<='z')
    {
        printf("%2c", n );
        n++;
    }


}
