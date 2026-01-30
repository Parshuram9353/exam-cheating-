//Develop a program to swap two variable value using call by value and call by reference
#include <stdio.h>

// Function declarations
void cbyvalue(int a, int b);
void cbyref(int *a, int *b);

int main()
{
    int a, b;

    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);

    printf("\nCALL BY VALUE\n");
    cbyvalue(a, b);

    printf("After call by value in main:\n");
    printf("a = %d  b = %d\n", a, b);

    printf("\nCALL BY REFERENCE\n");
    cbyref(&a, &b);

    printf("After call by reference in main:\n");
    printf("a = %d  b = %d\n", a, b);

    return 0;
}

// Call by Value function
void cbyvalue(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;

    printf("Inside call by value:\n");
    printf("a = %d  b = %d\n", a, b);
}

// Call by Reference function
void cbyref(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
