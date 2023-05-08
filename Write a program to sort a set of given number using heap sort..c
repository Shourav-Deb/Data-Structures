/*
* Write a program to sort a set of given number using heap sort.
*/

#include <stdio.h>

void heap_sort(int[], int);
void heap_sorting(int[], int, int);

int main() {
    int numbers[10] = {8, 3, 6, 2, 9, 1, 4, 5, 10, 7};
    int n = 10;

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    heap_sort(numbers, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

void heap_sort(int numbers[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heap_sorting(numbers, n, i);
    }


    for (int i = n - 1; i >= 0; i--) {

        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;

        heap_sorting(numbers, i, 0);
    }
}

void heap_sorting(int numbers[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && numbers[left] > numbers[largest]) {
        largest = left;
    }

    if (right < n && numbers[right] > numbers[largest]) {
        largest = right;
    }


    if (largest != i) {

        int temp = numbers[i];
        numbers[i] = numbers[largest];
        numbers[largest] = temp;

        heap_sorting(numbers, n, largest);
    }
}
