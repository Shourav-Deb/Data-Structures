/*
1. Write a program to build a max heap from a given set of numbers.
2. Write a program to extract maximum from a max heap.
*/

#include <stdio.h>

void max_heap(int arr[], int n, int i) {                                        /// Heap Creation Function
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heap(arr, n, largest);
    }
}

void create_heap(int arr[], int n) {                                        /// Heap Creation
    for (int i = n/2 - 1; i >= 0; i--)
        max_heap(arr, n, i);
}

int extract_max(int arr[], int *n) {                                        /// Extraction Max Heap

    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    max_heap(arr, *n, 0);

    return max;
}


int main() {
    int arr[10], size;

    do
    {
    printf("Enter size of the tree: ");
    scanf("%d", &size);
    if(size>10)
    printf("Max size is 10. Try Again.\n\n");
    } while(size>10);

    printf("\n");
    for(int i=0; i<size; i++)
    {
        printf("Enter %d no element in the tree: ", i+1);
        scanf("%d", &arr[i]);
    }

    create_heap(arr, size);

    printf("\n1. Max Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        printf("\n");

    int max = extract_max(arr, &size);
    printf("\n2. Extracted Maximum Value: %d\n", max);

    printf("   Max Heap after Extraction: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
