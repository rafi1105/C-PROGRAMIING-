#include <stdio.h>
#include <string.h>
int main()
{
    char ch1[20],ch2[20];
    int n,i=0;
    scanf("%[^\n] %[^\n]", ch1, ch2);
   while (ch1[i] == ch2[i]&&ch1!='\0'&&ch2!='\0')
   i++;
   if (n==0)
    
        printf("2 string are same");
    else 
        printf("2 string are not same");
return 0;
}