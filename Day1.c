#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, x;

    printf("Enter number of elements (n): "); 
    if (scanf("%d", &n) != 1) {
        printf("Error reading input size.\n");
        return 1;
    }

    int *arr = (int*)malloc((n + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers separated by space: ", n); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to insert (1 to %d): ", n + 1); 
    scanf("%d", &pos);

    printf("Enter element to insert: "); 
    scanf("%d", &x);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Please enter between 1 and %d.\n", n + 1);
        free(arr);
        return 1;
    }

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;
    n++; 

    printf("Updated array: "); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}