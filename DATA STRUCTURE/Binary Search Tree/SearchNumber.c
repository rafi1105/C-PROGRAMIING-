#include<stdio.h>
 
int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
 
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;
    
}
 
int main(){
    // Unsorted array for linear search
    // int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    // int size = sizeof(arr)/sizeof(int);
 
    // Sorted array for binary search
    int arr[50] ;
    int size,element;
    printf("enter the number of array size");
    printf("\n");
    scanf("%d",&size);
    printf(" enter the element of array \n");
    for (int i = 0; i < size; i++)
    scanf (" %d",&arr[i]);
    printf("enter the element \n");
    scanf("%d",&element);
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}
