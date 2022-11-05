#include <stdio.h>
int InputArray ( int array [], int size)
{
    printf (" please input the array .......\n");
    for ( int i=0; i<size; i++ )
    {
        scanf ("%d", &array[i]);
    }
}
 int Insertion( int array [], int size)
 {
    int temp;
    for ( int i=1; i<size; i++ ) // 3<4
    {
        for (int j=i; j>0 ; j--) // j=2  2>=0
        { 
           
            if ( array[j] < array[j-1]  ) // array[3] < array [2]= -1<4
            {
                temp = array[j-1]; //temp = -1
                array[j-1]=array [j]; // array[3] = 4
                array [j]=temp; // array [2]= -1
            }
        }
    }
printf (" the array is.... \n");
    for ( int i=0; i<size; i++ )
    {
        printf ("%d ", array[i]);
    }
 }
/* int printArray ( int array[], int size )
{
    printf (" the array is.... \n");
    for ( int i=0; i<size; i++ )
    {
        printf ("%d ", array[i]);
    }
} */
int main ()
{
    int array[30],size;
    printf (" please input the array size .......\n");
    scanf ("%d", &size);
   InputArray ( array , size);
   Insertion(array,size);
  // printArray ( array,size);
    return 0;

}