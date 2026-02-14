#include <stdio.h>

int main() {
    int n;
    int isIdentity = 1;  // Flag: 1 means true, 0 means false
    
    // Input: size of the matrix
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    
    // Declare the matrix
    int matrix[n][n];
    
    // Input: matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Check if it's an Identity Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check diagonal elements (should be 1)
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            }
            // Check non-diagonal elements (should be 0)
            else {
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if (isIdentity == 0) {
            break;  // Exit outer loop if already found it's not identity
        }
    }
    
    // Output result
    if (isIdentity == 1) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }
    
    return 0;
}