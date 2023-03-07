/// Write a code to push, pop, peek/top & Print from a stack in array.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int stack[5];
    int size = 5;
    int index = -1;
    int value;
    int choice;

    while(1)
    {

        printf("1.Push.\n");
        printf("2.Pop.\n");
        printf("3.Peek.\n");
        printf("4.Print.\n");
        printf("5.Exit.\n");
        printf("Choose your option: ");
        scanf("%d",&choice);

        if(choice==5)
        {
            break;
        }

        else if(choice==1)                                                                                                  /// code for push in stack
        {
            if(index==size-1)
            {
                printf("\n\nSorry, The stack is full. Pop some element to push.\n\n");
            }

            else
            {
                index++;
                printf("\n\nEnter element to push: ");
                scanf("%d",&value);
                stack[index]=value;
            }
            printf("Element Pushed.\n\n");
        }

        else if(choice==2)                                                                                                  /// code for pop from stack
        {
            if(index==-1)
            {
                printf("\nOpps, Stack is empty. Push some element to pop.\n\n");
            }
            else
            {
                index--;
                printf("\nElement poped.\n\n");
            }
        }

        else if(choice==3)                                                                                                  /// code for peek in stack
        {
            if(index==-1)
            {
                printf("\nHey, Stack is empty. Push some element then peek dude.\n\n");
            }
            else
            {
                printf("\n%d, is the top element.\n\n",stack[index]);
            }
        }

        else if(choice==4)                                                                                                  /// code for print stack
        {
            if(index==-1)
            {
                printf("\nHey, Stack is empty. Push some element then print dude.\n\n");
            }
            else
            {
                for(int j=index; j>-1; j--)
                    printf("\n\t%d",stack[j]);
                printf("\nAll element's printed as stack_[LIFO].\n\n");
            }
        }

        else
        {
            printf("\nHey, Wrong Input. Read & try again.\n\n");
        }
    }
}
