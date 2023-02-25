/* Question
-------------
Write a program to store 10 elements (given by keyboard) in a linked list. You have to write following functions.
a) insert the element at the first of the list.
b) insert the element at the last of the list.
c) insert the element as the nth element of the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node *start = NULL;

struct node                                                 /// Created structure.
{
    int data;
    struct node *next;
};

void insert_beginning(int x)                                /// Function to add element at  first.
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->next = start;
    start = temp;
}

void  insert_end(int x)                                      /// Function to add element at last.
{
    struct node *temp1, *current;
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = x;
    temp1->next = NULL;

    if(start == NULL)
        start = temp1;
    else
    {
        current = start;

        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp1;
    }
}

void insert_at_n_p(int x, int y)                               /// Function to add element at nth position.
{

    struct node *temp2, *prev, *current;
    temp2 = (struct node*)malloc(sizeof(struct node));
    temp2->data = y;
    temp2->next = NULL;
    current = start;

    if(x<2)
    {
        temp2->next= current;
        start =temp2;
    }
    else
    {
        for(int i=1; i<x; i++)
        {
            prev = current;
            current = current->next;
        }

        temp2->next= current;
        prev->next =temp2;
    }
}

void print_list()                                               /// Function to print.
{
    struct node *current = start;
    printf("\n\n==} Your Element Link List is: \n");
    while(current != NULL)
    {
        printf("\t%d\n", current ->data);
        current = current->next;
    }
    printf("\n\n");
}

int main()
{
    int b,c,d,e,f,g,element_count=1;


    printf("* Enter Element to Begin.");
    printf("\n>> Enter Digit: ");
    scanf("%d", &b);
    insert_beginning(b);

    while(element_count<10)                                     /// Loop until 10 element stores.
    {
        printf("\n\n");
        printf("------------  Menu  ------------\n\n");
        printf("1. Store Element At Beginning.\n");
        printf("2. Store Element At End.\n");
        printf("3. Store Element At a Position.\n");
        printf("4. Print List.\n\n");
        printf("Your Choice: ");
        scanf("%d", &c);

        if(c==1)
        {
            printf("\n>> Enter Digit: ");
            scanf("%d", &d);
            element_count++;
            insert_beginning(d);
        }
        else if(c==2)
        {
            printf("\n>> Enter Digit: ");
            scanf("%d", &e);
            element_count++;
            insert_end(e);
        }
        else if(c==3)
        {
            printf("\n>> Enter Position: ");
            scanf("%d", &f);
            if(f>element_count+1 || f==0)
            {
                printf("\nYou have %d element in your list. Choose position between 1 to %d.", element_count,element_count+1);
            }
            else
            {
                printf("\n>> Enter Digit: ");
                scanf("%d", &g);
                element_count++;
                insert_at_n_p(f,g);
            }
        }
        else if(c==4)
        {
            print_list();
        }
        else
        {
            printf("\n->> Wrong Input. <<-");
        }
    }
    printf("\n\nYou have successfully stored 10 elements.");
    print_list();


    return 0;
}
