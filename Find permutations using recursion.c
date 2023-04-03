// C program to generate permutations using recursion


#include <stdio.h>
#include <string.h>


void swap(char* x, char* y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


void permute(char a[], int start, int lenth)
{
	if (start == lenth)
		printf("\t%s\n", a);
	else {
		for (int i = start; i <= lenth; i++) {
			swap((a + start), (a + i));
			permute(a, start + 1, lenth);
			swap((a + start), (a + i));
		}
	}
}


int main()
{
	char str[] = "SCD";
	int n = strlen(str);
	printf("Permutation of %s are:\n", str);
	permute(str, 0, n - 1);


	return 0;
}


