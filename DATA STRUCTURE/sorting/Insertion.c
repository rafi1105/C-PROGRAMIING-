#include <stdio.h>
void insertionSort(int data[], int size) 
{
  for (int step = 1; step < size; step++) 
  {
    int larger = data[step];
    int j = step-1;
    while (larger < data[j] && j >= 0) 
    {
      data[j+1] = data[j];
      j--;
    }
    data[j + 1] = larger;
  }
}
void printData(int data[], int size) 
{
  for (int i = 0; i < size; i++) 
  {
    printf("%d ", data[i]);
  }
}

int main() {
  int data[20];
  int size;
  printf ("enter the size\n");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  scanf("%d",&data[i]);
  insertionSort (data, size);
  printf ("Sorted data in order:\n");
  printData (data, size);
}