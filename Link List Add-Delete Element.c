/// Create a function to [add-delete] data at [beginning-last-n position]. Also create a function to delete data by finding the data.   [Linked List]



#include <stdio.h>
#include <stdlib.h>

struct node *start = NULL;

struct node                                                      /// Created structure.
{
    int data;
    struct node *next;
};

void insert_beginning(int x)                                   /// Function to add data at first.
{
    printf("\n\n==} After Adding Data At First Link List is: \n");

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = start;
    start = temp;
}

void delete_beginning()                                       /// Function to delete data at first.
{
    printf("\n\n==}  After Deleting Data At First Link List is: \n");

    struct node *curr;
    curr = start;
    curr = curr->next;
    free(start);
    start = curr;
}

void  insert_last(int x)                                     /// Function to add data at last.
{
    printf("\n\n==} After Adding Data At Last Link List is: \n");

    struct node *temp1, *curr1;
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = x;
    temp1->next = NULL;

    if(start == NULL)
        start = temp1;
    else
    {
        curr1 = start;

        while(curr1->next != NULL)
        {
            curr1 = curr1->next;
        }
        curr1->next = temp1;
    }
}

void  delete_last()                                           /// Function to delete data at last.
{
    printf("\n\n==} After Deleting Data At Last Link List is: \n");

    struct node *previous, *current;

    if(start != NULL)
    {
        current = start;

        while(current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        free(current);
        previous->next = NULL;
    }
}

void insert_at_n_p(int x, int y)                               /// Function to add data at nth position.
{
    printf("\n\n==} After Adding Data At %d Position Link List is: \n",x);

    struct node *temp2, *prev, *current;
    int i=1;
    temp2 = (struct node*)malloc(sizeof(struct node));
    temp2->data = y;
    temp2->next = NULL;
    current = start;

    if(start == NULL)
        start = temp2;

    else
    {
        while(current->next != NULL && i<x)
        {
            prev = current;
            current = current->next;
            i++;
        }

        temp2->next= current;
        prev->next =temp2;
    }
}

void delete_at_n_p(int x)                               /// Function to delete data at nth position.
{
    printf("\n\n==} After Deleting Data At %d Position Link List is: \n",x);

    struct node *prev, *current;
    current = start;
    int i = 1;
    if(start != NULL)
    {
        while(current->next != NULL && i<x)
        {
            prev = current;
            current = current->next;
            i++;
        }
        prev->next = current->next;

    }
}

void delete_at_n_v(int x)                               /// Function to delete data by finding the data.
{
    printf("\n\n==} After Deleting Data By Finding Data %d Link List is: \n",x);

    struct node *prev, *current;
    current = start;
    int i = 1;
    if(start != NULL)
    {
        while(current->next != NULL && current->data!=x)
        {
            prev = current;
            current = current->next;
            i++;
        }
        prev->next = current->next;

    }
}

void print_list()                                               /// Function to print.
{
    struct node *current = start;
    while(current != NULL)
    {
        printf("\t%d\n", current ->data);
        current = current->next;
    }
    printf("\n\n");
}

int main()
{
    insert_beginning(60);
    print_list();
    insert_last(80);
    print_list();
    insert_at_n_p(2,70);
    print_list();

    insert_beginning(60);
    print_list();
    insert_last(80);
    print_list();
    insert_at_n_p(2,70);
    print_list();

    delete_beginning();
    print_list();
    delete_last();
    print_list();
    delete_at_n_p(3);
    print_list();
    delete_at_n_v(60);
    print_list();


    return 0;
}
