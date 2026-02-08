#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n <= 0) return 0; 

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d sorted integers separated by space: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int j = 0; 
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;             
            arr[j] = arr[i]; 
        }
    }

    int unique_count = j + 1;

    printf("Unique elements: ");
    for (int i = 0; i < unique_count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}