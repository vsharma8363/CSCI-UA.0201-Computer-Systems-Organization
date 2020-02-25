// When an array is passed into a function, it is treated as a pointer, and on 64-bit machines, pointers have 8 bytes, meaning the value of sizeof(arr) will be 8, not the actual length of the array. You will be required to pass in the length of the array as a variable when printing the array.

#include <stdio.h>

void printArray(int arr[], int len)
{
    int i;
    int arr_size = len; //sizeof(arr) / sizeof(arr[0]);
  
    
    //int len=sizeof(*arr)/sizeof(arr[0]);
        
    for (i = 0; i < arr_size; i+=1)
        printf("%d\n", arr[i]); 
} 
  
int main() 
{ 
    int arr[5] = { 1, 2, 3, 4, 5 };
    // You cannot extract the size information of an array using a pointer
    printArray(arr, sizeof(arr)/sizeof(*arr));
    return 0; 
} 
