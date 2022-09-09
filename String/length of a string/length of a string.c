#include <stdio.h>
void main()
{
    char str1[50];
    int i, l = 0;
 
    printf("Input a string : ");
    scanf("%s", str1);
    for (i = 0; str1[i] != '\0'; i++)
    {
        l++;
    }
   printf(" the lenght is : %d\n",l);
}

