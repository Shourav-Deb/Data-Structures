// C program to find summation of array elements using recursion

#include <stdio.h>


int sum(int arr[], int start, int len)  // Function for recursively find the sum of elements in an array
{
    if(start >= len)
        return 0;
        
    return (arr[start] + sum(arr, start + 1, len));
}

int main()
{
    int arr[15];
    int size, i, summation;
    

    do{
    printf("Enter size of the array: ");
    scanf("%d", &size);
    if(size>10)
    printf("Max size is 10. Try Again.\n\n");
    }while(size>10);
    
    printf("\n");
    for(i=0; i<size; i++)
    {
        printf("Enter %d no element in the array: ", i+ 1);
        scanf("%d", &arr[i]);
    }
    
    
    summation = sum(arr, 0, size);
    printf("\nSum of array elements: %d", summation);
    
    return 0;
}

