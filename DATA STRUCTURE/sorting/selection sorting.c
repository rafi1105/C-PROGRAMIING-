#include <stdio.h>
int printArray ( int array[], int size )
{
    printf (" the array is.... \n");
    for ( int i=0; i<size; i++ )
    {
        printf ("%d ", array[i]);
    }
}
int InputArray ( int array [], int size)
{
    printf (" please input the array .......\n");
    for ( int i=0; i<size; i++ )
    {
        scanf ("%d", &array[i]);
    }
}
int firstNumber ( int array [], int size){
    int select;
    select=array[0];
}
int sortArray (int array[],int size ,int select)
{
    int i,up,temp,n;
    n=size;

    while ( size != 1){ // 8 0 9
        select=array[0]; // select = 8
    for ( int i=1; i < size ; i++ ) // 1<2
    {
        if ( select < array[i] ) // 8<0
        {
            select = array[i]; // select = 8
            up=i; //up =0
        }
        else {
            up=0;
        }
    }
printf (" \n %d largest number in %d index \n", select,up);
    temp=array[size-1]; // temp = 0
    array[size-1]=select; // array[1]=8
    array[up]=temp; // array[0]= 0
    size--; // size = 1
    }
    printf ("\n new array is.... \n");
    for ( int i=0; i < n; i++ )
    {

printf (" %d ",array[i]);
    } 

}
int main ()
{
    int array[30],size,select;
    printf (" please input the array size .......\n");
    scanf ("%d", &size);
   InputArray ( array , size);
   select=firstNumber ( array, size);
   sortArray (array, size , select);
 // printArray ( array,size);

    return 0;

}