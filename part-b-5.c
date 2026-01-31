//Develop a program to sort a list of N elements using Insertion Sort

#include<stdio.h>

int main()
{
    int a[100], n, i, j, item;

    printf("enter the size of an array\n");
    scanf("%d", &n);

    printf("enter the array elements\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("entered elements are\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    for(i = 1; i < n; i++)
    {
        item = a[i];
        j = i - 1;

        while(j >= 0 && item < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = item;
    }

    printf("sorted array\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
