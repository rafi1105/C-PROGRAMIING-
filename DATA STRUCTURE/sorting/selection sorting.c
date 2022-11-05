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
 /* int sortArray (int array[],int size ,int select)
{
    int i,up,temp,n;
    n=size; // n=4
                        // 0 1 2 3
    while ( size != 1)
{ 
        // 5 5 4 6
        select=array[0]; // select = 5
             up=0;
    for ( int i=1; i < size ; i++ ) //  1<3
    {
        if ( select < array[i] ) // 5<6
        {
            select = array[i]; // select = 6
            up=i; //up =1
        }
        else if ( select == array[i] ) //
        
            {
             select = array[i];
             up=i; // up= 
            }
        
    }
}
printf (" \n %d largest number in %d index \n", select,up); // 5 5 4 6
    temp=array[size-1]; // temp = 5
    array[size-1]=select; // array[3]=6
    array[up]=temp; // array[1]= 5
    size--; // size = 3
    
    printf ("\n new array is.... \n");
    for ( int i=0; i < n; i++ )
    {

printf (" %d ",array[i]);
    } 

} */
int main ()
{
    int array[30],size,select;
    printf (" please input the array size .......\n");
    scanf ("%d", &size);
   InputArray ( array , size);
   select=firstNumber ( array, size);
    // sortArray (array, size , select);
  printArray ( array,size);

    return 0;

}