#include <stdio.h>
#include <string.h>
int main()
{
    char ch1[20],ch2[20];
    int n;
    scanf("%[^\n] %[^\n]", ch1, ch2);
    n=strcmp(ch1, ch2);
    if (n==0)
    
        printf("2 string are same");
    else 
        printf("2 string are not same");
return 0;
}