//Queue operations
#include <stdio.h>

#define SIZE 4

// Function declarations
void qinsert(int item);
void qdelete();
void qdisplay();

// Queue variables
int q[SIZE];
int front = -1, rear = -1;

int main()
{
    int item, op;

    do {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                qinsert(item);
                break;

            case 2:
                qdelete();
                break;

            case 3:
                qdisplay();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option\n");
        }
    } while (op != 4);

    return 0;
}

// Insert operation
void qinsert(int item)
{
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }

    q[rear] = item;
    printf("Inserted %d into queue\n", item);
}

// Delete operation
void qdelete()
{
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element = %d\n", q[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

// Display operation
void qdisplay()
{
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents:\n");
    for (i = front; i <= rear; i++) {
        printf("%d\n", q[i]);
    }
}
