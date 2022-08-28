//. Write a C program to enter a number and print its digit in reverse order
#include <stdio.h>
int main() {
    int num, rnum = 0, rem;
    printf("Enter any number: ");
    scanf("%d", &num);
    printf(" Reverse number: \n");
    while (num != 0) {
        rem = num % 10; 
        printf("%d", rem);
        num = num / 10;
    }
    
    return 0;
}
