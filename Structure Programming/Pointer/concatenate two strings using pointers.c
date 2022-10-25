#include <stdio.h>
int main()
{
    char aa[100], bb[100];
    scanf("%[^\n] ",aa);
      scanf("%[^\n]",bb);
    char *a = aa;
    char *b = bb;
    while(*a) 
    {
        a++;    
    }
    while(*b)  
    {
        *a = *b;
        b++;
        a++;
    }
    *a = '\0';
    printf("The string after concatenation is: %s ", aa);
    return 0;
}