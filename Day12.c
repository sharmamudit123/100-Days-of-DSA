#include <stdio.h>
int main() {
    int m, n;
    int isSymmetric = 1; 

    printf("Enter number of rows and columns (m n): ");
    if (scanf("%d %d", &m, &n) != 2) return 1;

    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int arr[m][n];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != arr[j][i]) {
                isSymmetric = 0; 
                break;
            }
        }
        if (isSymmetric == 0) break; 
    }

    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}