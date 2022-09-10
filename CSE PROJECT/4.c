#include<stdio.h>

void input_Num(char str[], int i)
{
    printf("Enter the String: ");
    gets(str);
    for(i=0; str[i]!='\0'; i++);
    if (i<5)
    printf("your number is not 5 digit number");
    else
    printf("Okay");
}    
int main()
{
    int i,n;
    char str[20];
    input_Num(str, i);
    return 0;
}