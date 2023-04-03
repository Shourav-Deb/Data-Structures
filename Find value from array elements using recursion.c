// C program to find value from array using recursion

#include <stdio.h>

void print(int arr_index, int value){
    if (arr_index != 0)
		printf("->> Element %d is present at position %d.\n", value, arr_index);
	else
		printf("->> Element %d is not present.\n", value);
}

int linear_Search(int ele[], int len, int value) {      // Recursive function to search value in ele[]
	
	int pos;
	len--;

	if (len >= 0) {
		if (ele[len] == value)
			return len+1;
		else
			pos = linear_Search(ele, len, value);
	}
	else
		return 0;

	return pos;
}


int main() {
	int array[15];
	int size;
	int i, value, choice, arr_index = 0;

    do{
    printf("Enter size of the array: ");
    scanf("%d", &size);
    if(size>10)
    printf("Max size is 10. Try Again.\n\n");
    }while(size>10);
    
    printf("\n");
    for(i=0; i<size; i++)
    {
        printf("Enter %d no element in the array: ", i+1);
        scanf("%d", &array[i]);
    }
    
    while(1){
    printf("\n1.Enter Element to find in array.\n");
    printf("2.Exit.\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    if(choice==1)
    {
    printf("\nEnter Element to find:- ");
    scanf("%d", &value);
	arr_index = linear_Search(array, size, value);
	print(arr_index, value);
    }
    else if(choice==2)
    {
        break;
    }else
    printf("\n>> Wrong Input.\n");
	}
	return 0;
}

