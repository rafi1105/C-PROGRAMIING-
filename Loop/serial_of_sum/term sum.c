// Write a program in C to find the sum of the series 1 +11 + 111 + 1111 + .. n terms.

#include <stdio.h>

int main()
{
    int t,num,sum=0;
    printf(" enter the number of terms to process :");
    scanf("%d", &t);
    printf(" enter the number of  process :");
    scanf("%d", &num);
    printf("The series is :");
    for (int i = 0; i < t; i++) // how many terms to process
    {
        sum=(sum*10)+num;
        
        printf("%2d ",sum);
        for (int j = i ; j <= i; j++)
        {
            printf(" + ");
        }

    }

return 0;
}
