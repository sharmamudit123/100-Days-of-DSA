#include <stdio.h>
int main() {
    int m, n;

    printf("Enter number of rows and columns (m n): ");
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    int A[m][n];
    int B[m][n];

    printf("Enter elements of the FIRST matrix (%d rows by %d columns):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of the SECOND matrix (%d rows by %d columns):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\n--- Resultant Matrix after addition ---\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}