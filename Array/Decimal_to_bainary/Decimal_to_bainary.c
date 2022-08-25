// C Program to Convert Decimal to Binary Using Arrays
#include <stdio.h>
int main(){
    int arr[10], num, i, j;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    for (i = 0; num > 0; i++){
        arr[i] = num % 2;
        num = num / 2;
    }
    printf("binary number is: ");
    for (j = i ; j >= 0; j--){
        printf("%d", arr[j]);
    }
    return 0;
}