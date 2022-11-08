#include <stdio.h>
int printArray ( int array[], int size )
{
    printf (" the array is.... \n");
    for ( int i=0; i<size; i++ )
    {
        printf ("%d ", array[i]);
    }
}
int InputArray ( int array [], in size)
{
    printf (" please input the array .......\n");
    for ( int i=0; i<size; i++ )
    {
        scanf ("%d", &array[i]);
    }
}

int main ()
{
    int array[30],size;
    printf (" please input the array size .......\n");
    scanf ("%d", &size);
   InputArray ( array , size);
   printArray ( array,size);
    return 0;

}