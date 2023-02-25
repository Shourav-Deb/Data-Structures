/* Question
-------------
Implement the following operation of a dynamic array.
a) add element
b) remove element
c) increase size of the array
d) decrease size of the array
e) free the memory
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, number, s_number;
    int *first_allocation;
    int new_number = -1;

    first_allocation = (int*) malloc(n * sizeof(int));

    printf("## Enter size of integer array: ");
    scanf("%d", &n);

    printf("\n");
    printf("## Enter %d integer numbers: ", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",(first_allocation+i));
        new_number++;
    }

    printf("\n");
    printf("## Entered %d numbers are: ", n);
    for(int i=0; i<n; i++)
    {
        printf("%d ",*(first_allocation+i));
    }

    while(1)
    {

        printf("\n\n");
        printf("--> Enter 1 to add another number.\n");
        printf("--> Enter 2 to remove a number.\n");
        printf("--> Enter 3 to print numbers.\n");
        printf("--> Enter 0 to close.\n");
        printf("* Enter your input: ");
        scanf("%d",&m);

        if(m==0)
            break;

        else if(m==1)                                                                                               /// Add element
        {
            printf("\n* Enter new number: ");
            scanf("%d",&number);
            new_number++;
            if(new_number >= n)
            {

                first_allocation = (int*)realloc(first_allocation, sizeof(int)*(new_number*2));                     /// Increase size of an array
                n=new_number*2;
            }

            first_allocation[new_number]=number;
        }

        else if(m==2)                                                                                               /// Remove element
        {

            printf("\n* Enter serial number of the integer number: ");
            scanf("%d",&s_number);
            if(s_number>new_number+1)
                printf("~~ Serial not exists in array. ~~\n");
            else
            {
                for (int i = s_number - 1; i < n -1; i++)
                {
                    first_allocation[i] = first_allocation[i+1];
                }
                new_number --;
                n=new_number;
                first_allocation = (int*)realloc(first_allocation, sizeof(int)*(new_number+1));                     /// Decrease size of an array
            }
        }

        else if(m==3)
        {
            printf("\n## Entered %d numbers are: ", new_number+1);
            for(int i=0; i<=new_number; i++)
            {
                printf("%d ",*(first_allocation+i));
            }
            printf("\n");
        }

        else
        {
            printf("!! Wrong input !!\n");
        }
    }

    free(first_allocation);                                                                                    /// free the memory
    return 0;
}
