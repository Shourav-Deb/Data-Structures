// C program to find dot product of vectors using recursion

#include <stdio.h>

int dot_product(int a[], int b[], int n) {      //  dot product of vectors
    if (n == 0) {
        return 0;
    } else {
        return (a[n-1] * b[n-1]) + dot_product(a, b, n-1);
    }
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Dot product of vectors a and b is %d.", dot_product(a, b, n));
    return 0;
}

