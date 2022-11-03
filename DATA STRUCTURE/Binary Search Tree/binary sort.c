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
                return (a[mid]) ;
            }
        }
        return -1;
}
int main ()
{
    int num,x=0,i,a[20],element, searchIndex,temp,j,data[20],found;
    printf("Enter the element number : ");
    scanf("%d",&num);
    printf("please enter the array number : \n");
    for (i=0; i<num; i++)
    {
        scanf("%d",&a[i]);
    }
    // copy the data  array
    for (i=0; i<num; i++)
    data[i]=a[i];
    printf("enter the element value : \n");
    scanf("%d",&element);
        for (i=0; i<num; i++)
        {
            
            if (a[i]>a[i+1]) // not sorted yet
            {
                x++;
                
            }
        }
   printf ("%d is x \n",x);
   if (x>0)
    {
        printf  ( " array  not is  sorted\n");
        for ( i =0; i<num ;i++)
        {
        for ( j=0; j<num-1 ; j++)
        {
        if (a[j]>a[j+1])
        {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        }
        }
        }
        printf(" after sorting : \n");
        for ( i =0 ; i< num ; i++)
        printf(" %d ", a[i]);
        searchIndex= binarySearch( a, num, element);
            for ( i=0 ; i< num ; i++)
            if ( searchIndex == data[i])
            found=i+1;

        printf("\n we found %d elements in index %d\n", element,found);
        return 0;
    } 
   
  
}