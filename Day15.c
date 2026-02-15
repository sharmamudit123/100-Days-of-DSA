#include <stdio.h>

int main() {
    int m, n;
    
    // Input: number of rows and columns
    printf("Enter number of rows and columns (m n): ");
    scanf("%d %d", &m, &n);
    
    // Declare the matrix
    int matrix[m][n];
    
    // Input: matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Calculate sum of primary diagonal
    int sum = 0;
    int diagonalSize = (m < n) ? m : n;  // Take minimum of m and n
    
    for (int i = 0; i < diagonalSize; i++) {
        sum += matrix[i][i];  // Primary diagonal: row index = column index
    }
    
    // Output the result
    printf("Sum of primary diagonal elements: %d\n", sum);
    
    return 0;
}