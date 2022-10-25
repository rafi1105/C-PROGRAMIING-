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
int linearSearch ( int a[], int num , int element )
{
    int i;
    for ( i = 0; i < num; i++ )
    if ( a[i] == element )
    {
        return (i+1);
    }
   return -1;
}
int main ()
{
    int num,x=0,i,a[20],element, searchIndex;
    printf("Enter the element number : ");
    scanf("%d",&num);
    printf("please enter the array number : \n");
    for (i=0; i<num; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element value : \n");
    scanf("%d",&element);
        for (i=0; i<num; i++)
        {
            
            if (a[i]>a[i+1]) // not sorted yet
            {
                x++;
                
            }
        }
   
   if (x>0)
    {
        int searchIndex= linearSearch( a, num, element);
        printf("we found %d elements in index %d\n", element,searchIndex);
        return 0;
    } 
    if (x==0)
    {
         searchIndex= binarySearch( a, num, element);
        printf("we found %d elements in index %d\n", element,searchIndex);
        return 0;
    }
   if ( searchIndex == -1)
    {
        printf(" %d value is not available in this array ", element);
    } 
}