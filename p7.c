//Develop a program to sort a list of N elements using a quick sort

#include <stdio.h>

// Function declarations
void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main()
{
    int a[100], n, i;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

// Quick sort function
void quicksort(int a[], int low, int high)
{
    int p;
    if (low < high) {
        p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

// Partition function
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j) {

        while (i <= high && a[i] <= pivot) {
            i++;
        }

        while (a[j] > pivot) {
            j--;
        }

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Place pivot in correct position
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
