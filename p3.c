//Write functions to implement string operations such as compare, concatenate, string length. Convince the parameter passing techniques

#include <stdio.h>

// Function declarations
void slength(char s[]);
void sconcat(char s1[], char s2[]);
void scompare(char s1[], char s2[]);

int main()
{
    char s1[50], s2[50];
    int op;

    do {
        printf("\n1. String Length\n");
        printf("2. String Concatenation\n");
        printf("3. String Comparison\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", s1);
                slength(s1);
                break;

            case 2:
                printf("Enter first string: ");
                scanf("%s", s1);
                printf("Enter second string: ");
                scanf("%s", s2);
                sconcat(s1, s2);
                break;

            case 3:
                printf("Enter first string: ");
                scanf("%s", s1);
                printf("Enter second string: ");
                scanf("%s", s2);
                scompare(s1, s2);
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

// Function to find string length (call by value of array address)
void slength(char s[])
{
    int i, len = 0;

    for (i = 0; s[i] != '\0'; i++) {
        len++;
    }

    printf("Length of string = %d\n", len);
}

// Function to concatenate two strings
void sconcat(char s1[], char s2[])
{
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        i++;
    }

    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';

    printf("Concatenated string = %s\n", s1);
}

// Function to compare two strings
void scompare(char s1[], char s2[])
{
    int i = 0, diff;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0')
            break;
        i++;
    }

    diff = s1[i] - s2[i];

    if (diff == 0) {
        printf("Strings are equal\n");
    } else if (diff > 0) {
        printf("First string is greater than second string\n");
    } else {
        printf("First string is less than second string\n");
    }
}
