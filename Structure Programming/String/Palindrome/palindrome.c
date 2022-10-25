#include <stdio.h>
int main ()
{
    char ch1 [20];
    int length=0,flag=1,i;
    scanf("%[^\n]",ch1);
    for (i= 0;ch1[i]!='\0';i++)
    {
        length++;
    }
    for(i=0;i<length/2;i++)
    {
        if(ch1[i]!=ch1[length-1-i])
        {
            flag=0;
        }
    }
    if (flag==1)
    {
        printf("palindrome");
    }
    else 
    printf("not palindrome");
}