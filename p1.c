//Develop a program to insert and delete an element at desired position in an array.

#include <stdio.h>

#define MAX 10

void insert(int a[], int *n, int pos, int ele);
void adelete(int a[], int *n, int pos);

int main()
{
    int a[MAX], i, pos, ele, op, n;

    printf("Enter the size of array (max 10): ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Array size exceeds limit\n");
        return 0;
    }

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    do {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                insert(a, &n, pos, ele);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                adelete(a, &n, pos);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option\n");
        }
    } while (op != 3);

    return 0;
}

void insert(int a[], int *n, int pos, int ele)
{
    int i;

    if (*n >= MAX) {
        printf("Insertion not possible. Array is full.\n");
        return;
    }

    if (pos <= 0 || pos > *n + 1) {
        printf("Invalid position\n");
        return;
    }

    for (i = *n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos - 1] = ele;
    (*n)++;

    printf("Array after insertion:\n");
    for (i = 0; i < *n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void adelete(int a[], int *n, int pos)
{
    int i;

    if (*n == 0) {
        printf("Deletion not possible. Array is empty.\n");
        return;
    }

    if (pos <= 0 || pos > *n) {
        printf("Invalid position\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }

    (*n)--;

    printf("Array after deletion:\n");
    for (i = 0; i < *n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
