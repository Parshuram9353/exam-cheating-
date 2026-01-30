//Implement recursive functions for Binary to Decimal Conversion

#include <stdio.h>
#include <math.h>

// Function declaration
int bindec(int bn, int i);

int main()
{
    int bn, dn;

    printf("Enter a binary number: ");
    scanf("%d", &bn);

    dn = bindec(bn, 0);

    printf("Decimal equivalent of binary number = %d\n", dn);

    return 0;
}

// Recursive function to convert binary to decimal
int bindec(int bn, int i)
{
    int r;

    // Base case
    if (bn == 0) {
        return 0;
    }

    // Last digit
    r = bn % 10;

    // Recursive call
    return (r * pow(2, i)) + bindec(bn / 10, i + 1);
}
