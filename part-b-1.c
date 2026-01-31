// Develop a program to Simulate the working of STACK providing the following operations– Insert, Delete and Display

#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

void push(int);
void pop();
void display();

int s[SIZE];
int top = -1;

int main()
{
    int item, op;
    do
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n\n");
        printf("enter option\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                printf("enter the item to be inserted\n");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    } while(op != 4);

    return 0;
}

void push(int item)
{
    if(top == SIZE - 1)
    {
        printf("stack overflow\n");
        return;
    }
    top++;
    s[top] = item;
}

void pop()
{
    if(top == -1)
    {
        printf("stack underflow\n");
        return;
    }
    printf("popped element = %d\n", s[top]);
    top--;
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("contents of stack\n");
    for(i = top; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
}
