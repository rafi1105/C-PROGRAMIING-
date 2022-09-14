#include <stdio.h>
int convert(int n);
void main() {
    int number;
    printf("enter the decimal number :");
    scanf("%d", &number); 
    printf("decimal (%d) = bainary (%d) \n",number,convert(number));
}
int convert(int n) {
    if (n ==0)
    return 0;
    else 
    return ((n%2)+10*convert(n/2));
}
