/// Write a code to enqueue, dequeue, peek/top & print from a queue in an array [using circular queue].

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
            if(front == ((rear+1)%size))
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
                rear = ((rear+1)%size);
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
                front=((front+1)%size);
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
                for(int i=front; i != rear; i=((i+1)%size))
                    printf("\n\t%d", queue[i]);
                    printf("\n\t%d", queue[rear]);
                printf("\nAll element's printed as Queue_[FIFO].\n\n");
            }
        }

        else
        {
            printf("\nHey, Wrong Input. Read & try again.\n\n");
        }
    }
}
