
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    int i,size, POS, item;
    int A[size];

    printf("Enter the size:");
    scanf("%d", &size);

 //   srand(time(0));

    for(i=0; i<size; i++){
        A[i] = rand()%100;
    }

    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }


    while(1){
        printf("\nEnter the Position: ");
        scanf("%d", &POS);
        printf("\nEnter the item: ");
        scanf("%d", &item);

        int j = size - 1;
        for(int j; j>=POS; j--){
            A[j+1] = A[j];
        }
        A[POS] = item;
        size = size+1;
        printf("\nArray Size: %d", size);
        printf("\nArray element are: ");
        for(i=0; i<size; i++){
            printf("%d ", A[i]);
        }
    }

}