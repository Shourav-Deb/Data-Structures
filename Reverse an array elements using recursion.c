// C program to reverse an array elements using recursion

#include <stdio.h>

void reverse(int arr[], int high, int low)      // Recursive function to reverse elements of a sub-array formed
{
    if (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        reverse(arr, high - 1, low + 1);
    }
}

int main(void)
{
    int arr[15];
    int size;

    do{
    printf("Enter size of the array: ");
    scanf("%d", &size);
    if(size>10)
    printf("Max size is 10. Try Again.\n\n");
    }while(size>10);

    printf("\n");
    for(int i=0; i<size; i++)
    {
        printf("Enter %d no element in the array: ", i+ 1);
        scanf("%d", &arr[i]);
    }

    reverse(arr, size - 1, 0);
    printf("\n->> Reversed Elements:- ");

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}


