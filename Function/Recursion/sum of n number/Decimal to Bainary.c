#include <stdio.h>
int convert(int n);
void main() {
    int no;
    printf("enter the decimal number :");
    scanf("%d", &no); // input the decimal number
    printf("decimal (%d) = bainary (%d) \n",no,convert(no));
}
int convert(int n) {
    if (n ==0)
    return 0;
    else 
    return ((n%2)+10*convert(n/2));
}
