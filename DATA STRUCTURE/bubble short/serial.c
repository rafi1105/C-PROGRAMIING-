#include<stdio.h>
int main ( )
{

    int arr [50];
    int i,j,size;
    scanf (" %d",&size);
    for (i=0;i<size;i++)
    {
        scanf ("%d",&arr[i]);
    }
   for (i=0;i<size;i++)
        for (j=0;j<size;j++)
        {
            if (arr[j] > arr[j+1])
                {
                // swap two numbers
                int temp = arr [ j ] ;
                arr [j] = arr [j+1] ;
                arr [ j + 1 ] = temp ;
                }
        }
    
    printf ( " \nAfter sorting : \n " ) ;
    for ( i = 0 ; i < size ; i++ ) {
        printf ( " % d " , arr [ i ] ) ;
   }
    printf ( " \n " ) ;
    return 0 ;
    }
