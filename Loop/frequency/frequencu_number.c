//. Write a C program to find frequency of each digit in a given integer
  
#include <stdio.h>

int main()
{
    long long num, n;
    int i, lastDigit,e;
    int freq[e];
    printf("Enter the frequency of each digit in a given integer: ");
    scanf("%d",&e);

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%lld", &num);

    /* Initialize frequency array with 0 */
    for(i=0; i<e; i++)
    {
        freq[i] = 0;
    }

    /* Copy the value of 'num' to 'n' */
    n = num; 

    /* Run till 'n' is not equal to zero */
    while(n != 0)
    { 
        /* Get last digit */
        lastDigit = n % 10;

        /* Remove last digit */
        n =n/10;

        /* Increment frequency array */
        freq[lastDigit]++;
    }

    /* Print frequency of each digit */
    printf("Frequency of each digit in %lld is: \n", num);
    for(i=0; i<e; i++)
    {
        printf("Frequency of %d = %d\n", i, freq[i]);
    }      

    return 0;
}