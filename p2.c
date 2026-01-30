//Develop a program to introduce 2D Array manipulation and implement Matrix multiplication and ensure the rules of multiplication are checked

#include <stdio.h>

#define MAX 5

int main()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int m, n, p, q;
    int i, j, k;

    printf("Enter the size of matrix A (rows cols): ");
    scanf("%d %d", &m, &n);

    printf("Enter the size of matrix B (rows cols): ");
    scanf("%d %d", &p, &q);

    // Rule of matrix multiplication
    if (n != p) {
        printf("Matrix multiplication is not possible\n");
        return 0;
    }

    if (m > MAX || n > MAX || p > MAX || q > MAX) {
        printf("Matrix size exceeds limit\n");
        return 0;
    }

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Initialize result matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            c[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Resultant Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
