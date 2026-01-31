//Develop a program to Simulate the working of Circular Queue providing the following operations–Insert, Delete and Display

#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

void cqinsert(int);
void cqdelete();
void cqdisplay();

int cq[SIZE], front = -1, rear = -1;

int main()
{
    int item, op;

    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n\n");
        printf("enter option\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                printf("enter item to be inserted\n");
                scanf("%d", &item);
                cqinsert(item);
                break;
            case 2:
                cqdelete();
                break;
            case 3:
                cqdisplay();
                break;
            case 4:
                exit(0);
        }
    } while(op != 4);

    return 0;
}

void cqinsert(int item)
{
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("circular queue is full\n");
        return;
    }

    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    cq[rear] = item;
}

void cqdelete()
{
    if(front == -1)
    {
        printf("circular queue is empty\n");
        return;
    }

    printf("deleted element = %d\n", cq[front]);

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void cqdisplay()
{
    int i;

    if(front == -1)
    {
        printf("circular queue is empty\n");
        return;
    }

    printf("contents of circular queue\n");

    if(front <= rear)
    {
        for(i = front; i <= rear; i++)
            printf("%d\n", cq[i]);
    }
    else
    {
        for(i = front; i < SIZE; i++)
            printf("%d\n", cq[i]);
        for(i = 0; i <= rear; i++)
            printf("%d\n", cq[i]);
    }
}
