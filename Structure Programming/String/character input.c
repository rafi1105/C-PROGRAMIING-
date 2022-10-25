#include <stdio.h>

int main ()
{
    char a[10];
   
    gets(a); // or scanf ("%[^\n]",a);
    printf("\n");
    printf(" input is: \n ");
    puts(a); // or printf("%s",a);

}