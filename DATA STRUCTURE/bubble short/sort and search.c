#include <stdio.h>
int binarySearch (int a[], int num, int element)
{
    int low=0,high=num-1,mid;
    mid = (high+low)/2;
        while ( low <= high )
        {
            mid = (high+low)/2;
            if (a[mid] < element)
            {
                low = mid + 1;
            }
            else if ( a[mid] > element)
            {
                high = mid -1;
            }
            if  ( a[mid] == element){
                return (mid+1) ;
            }
        }
        return -1;
}
int main ()
{
    int size, i,j, a[50], temp , element;
    printf(" enter the size of the array\n");
    scanf("%d", &size);
    printf(" enter the number of elements in the array\n");
    for (i=0; i<size; i++) {
    scanf("%d", &a[i]);
    }
    for (i=0; i<size; i++) 
    for (j=0; j<size; j++)
    if ( a[j] > a [j+1])
    {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
    }
    printf(" sorting is done\n");
    for (i=0; i<size; i++) 
    printf(" %d ", a[i]);
    printf("\n which element you want to search \n");
    scanf("%d ", &element );
     int searchIndex = binarySearch ( a,size,element);
    printf(" found %d elements %d index \n", element ,searchIndex);
    return 0;
    
}