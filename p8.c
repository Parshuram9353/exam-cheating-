//Develop C Program to Implement the search techniques of  a. Linear Search b. Binary Search

#include <stdio.h>

// Function declarations
void lsearch();
void bsearch();

int main()
{
    int op;

    do {
        printf("\n1. Linear Search");
        printf("\n2. Binary Search");
        printf("\n3. Exit");
        printf("\nEnter option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                lsearch();
                break;

            case 2:
                bsearch();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option\n");
        }
    } while (op != 3);

    return 0;
}

// Linear Search Function
void lsearch()
{
    int a[20], n, i, key, found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Key found at position %d\n", i + 1);
    } else {
        printf("Key not found\n");
    }
}

// Binary Search Function
void bsearch()
{
    int a[20], n, i, key;
    int low, high, mid, found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements in ascending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            found = 1;
            break;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (found == 1) {
        printf("Key found at position %d\n", mid + 1);
    } else {
        printf("Key not found\n");
    }
}
