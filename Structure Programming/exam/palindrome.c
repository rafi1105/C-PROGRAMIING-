#include <stdio.h>
int main ()
{
    char ch1 [20];
    int length=0,i;
    scanf("%[^\n]",ch1);
    for (i= 0;ch1[i]!='\0';i++)
    {
        length++; //4
    }
    for(i=0;i<length/2;i++) // i<2
    {
        if(ch1[i]!=ch1[length-1-i])
        {
           printf("not palindrome");
        }
    }
   
        printf("palindrome");
    
    
}