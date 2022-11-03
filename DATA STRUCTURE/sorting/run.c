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
                return a[mid];
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
    int num,x=0,i,a[20],element, searchIndex,j,temp,flag,data[20];
    printf("Enter the element size : ");
    scanf("%d",&num);
    printf("please enter the array number : \n");
    for (i=0; i<num; i++)
    {
        scanf("%d",&a[i]);
    }
    // copy the array
    for (i=0; i<num; i++)
    a[i]=data[i];
    printf("enter the element value : \n");
    scanf("%d",&element);
        for (i=0; i<num; i++)
        {

            if (a[i]>a[i+1]) // not sorted yet
            {
                x++;

            }
           // printf  ( " array  not is  sorted\n");
        }

   if (x>1)

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
         for (i=0 ; i< num ; i++)
         {
           if  (data [i] == searchIndex)
           printf ("%d is index ", i);
         }
         printf("\n we found %d elements in position %d\n", element,i);
        return 0;
    }
     /* else if (x==1)
    {
    printf  ( " array  is  sorted\n");
         searchIndex= binarySearch( a, num, element);
         for (i =0; i<num ;i++)
         {
            if (a[i]==searchIndex)
            i=flag+1;
         }
        printf("we found %d elements in position %d\n", element,flag);
        return 0;
    }
   if ( searchIndex == -1)
    {
        printf(" %d value is not available in this array ", element);
    } */
}
