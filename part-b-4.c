/* Develop a program to Simulate the working of a linked list
providing the following operations
a. Insert at the beginning
b. Insert at the end
c. Delete at the beginning
d. Delete at the end e. Display */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE addbeg(NODE, int);
NODE addend(NODE, int);
NODE delbeg(NODE);
NODE delend(NODE);
void display(NODE);
NODE getnode();

int main()
{
    int op, item;
    NODE first = NULL;

    do
    {
        printf("1.Insert node at beginning\n");
        printf("2.Insert node at the end\n");
        printf("3.Display\n");
        printf("4.Delete node at the beginning\n");
        printf("5.Delete node at the end\n");
        printf("6.Exit\n\n");
        printf("enter option\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                printf("enter the data to be inserted\n");
                scanf("%d", &item);
                first = addbeg(first, item);
                break;

            case 2:
                printf("enter the data to be inserted\n");
                scanf("%d", &item);
                first = addend(first, item);
                break;

            case 3:
                if(first == NULL)
                    printf("Linked list is empty\n\n");
                else
                {
                    printf("contents of linked list are\n");
                    display(first);
                }
                break;

            case 4:
                if(first == NULL)
                    printf("Linked list is empty\n\n");
                else
                    first = delbeg(first);
                break;

            case 5:
                if(first == NULL)
                    printf("Linked list is empty\n\n");
                else
                    first = delend(first);
                break;

            case 6:
                exit(0);
        }
    } while(op != 6);

    return 0;
}

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}

NODE addbeg(NODE first, int item)
{
    NODE temp;
    temp = getnode();
    temp->data = item;
    temp->link = first;
    return temp;
}

NODE addend(NODE first, int item)
{
    NODE temp, cur;
    temp = getnode();
    temp->data = item;
    temp->link = NULL;

    if(first == NULL)
        return temp;

    cur = first;
    while(cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return first;
}

void display(NODE first)
{
    NODE cur = first;
    while(cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->link;
    }
    printf("NULL\n\n");
}

NODE delbeg(NODE first)
{
    NODE cur = first;
    first = first->link;
    free(cur);
    return first;
}

NODE delend(NODE first)
{
    NODE cur = first, prev = NULL;

    if(first->link == NULL)
    {
        free(first);
        return NULL;
    }

    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    prev->link = NULL;
    free(cur);
    return first;
}
