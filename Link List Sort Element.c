/* Question
-------------
Create a sorted list function (small to big):
*/

#include <stdio.h>
#include <stdlib.h>

struct node *start = NULL;

struct node                                                 /// Created structure.
{
    int data;
    struct node *next;
};

void sort_list(int x)                                       /// Function to sort element.
{

    struct node *previous, *current, *temp;

    previous = NULL;
    current = start;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;


    if(start == NULL)
        start = temp;
    else if(start->data > x)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        while (current->data < x && current->next!= NULL)
        {
            previous = current;
            current = current->next;
        }

        if(current->next == NULL)
        {
            current->next = temp;
        }
        else
        {
            temp->next = previous->next;
            previous->next = temp;
        }
    }
}

void print_list()                                               /// Function to print.
{
    struct node *current = start;
    printf("\n\n==} Your Sorted Element Link List is: \n");
    while(current != NULL)
    {
        printf("\t%d\n", current ->data);
        current = current->next;
    }
    printf("\n\n");
}

int main()
{
    int a,b,*c;


    printf("* Enter Element to size: ");
    scanf("%d", &a);
    c = (int*)malloc( a * sizeof(int));
    printf("\n\n* Enter %d Element:\n", a);
    for(int j=0; j<a; j++)
        scanf("%d", &c[j]);

    for(int k=0; k<a; k++)
        sort_list(c[k]);

        print_list();
}




