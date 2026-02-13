#include <stdio.h>
int main() {
    int r, c;

    printf("Enter number of rows and columns (r c): ");
    if (scanf("%d %d", &r, &c) != 2) return 1;

    int matrix[r][c];

    printf("Enter elements of the matrix (%d x %d):\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    printf("\nSpiral Order: ");

    while (top <= bottom && left <= right) {
        
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++; 

        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--; 

        if (top <= bottom) { 
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--; 
        }

        if (left <= right) { 
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++; 
        }
    }
    printf("\n");

    return 0;
}