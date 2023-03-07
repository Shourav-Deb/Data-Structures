/// Write a code to enqueue, dequeue, peek/top & print from a queue in array.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int queue[5];
    int size = 5;
    int front = -1, rear = -1;
    int value;
    int choice;

    while(1)
    {

        printf("1.Enqueue.\n");
        printf("2.Dequeue.\n");
        printf("3.Peek.\n");
        printf("4.Print.\n");
        printf("5.Exit.\n");
        printf("Choose your option: ");
        scanf("%d",&choice);

        if(choice==5)
        {
            break;
        }

        else if(choice==1)                                                                                                  /// code for enqueue in queue.
        {
            if(rear == size-1)
                printf("\n\nSorry, The Queue is full. Dequeue some element to enqueue.\n\n");

            else if(front == -1 && rear == -1)
            {
                front++;
                rear++;
                printf("\n\nEnter element to enqueue: ");
                scanf("%d",&value);
                queue[rear]=value;
                printf("Element Enqueued.\n\n");
            }

            else
            {
                rear++;
                printf("\n\nEnter element to enqueue: ");
                scanf("%d",&value);
                queue[rear]=value;
                printf("Element Enqueued.\n\n");
            }
        }

        else if(choice==2)                                                                                                  /// code for dequeue from queue.
        {

            if(front == -1 && rear == -1)
            {
                printf("\nOpps, Queue is empty. Enqueue some element to dequeue.\n\n");
            }

            else if (front == rear)
            {
                printf("\n%d Dequeued.\n\n", queue[front]);
                front--;
                rear--;
            }

            else
            {
                printf("\n%d Dequeued.\n\n", queue[front]);
                for(int i=0; i<rear; i++)
                    queue[i] = queue[i+1];
                rear--;
            }
        }

        else if(choice==3)                                                                                                  /// code for peek in queue.
        {

            if(front == -1 && rear == -1)
            {
                printf("\nHey, Queue is empty. Enqueue some element then peek dude.\n\n");
            }

            else
            {
                printf("\n%d, is the first element.\n\n",queue[front]);
            }
        }

        else if(choice==4)                                                                                                  /// code for print queue.
        {
            if(front == -1 && rear == -1)
            {
                printf("\nHey, Queue is empty. Enqueue some element then print dude.\n\n");
            }
            else
            {
                for(int i=0; i < rear+1; i++)
                    printf("\n\t%d", queue[i]);
                printf("\nAll element's printed as Queue_[FIFO].\n\n");
            }
        }

        else
        {
            printf("\nHey, Wrong Input. Read & try again.\n\n");
        }
    }
}
