#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i;
    int comparisons = 0;
    int found_index = -1; 

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    printf("Enter %d integers separated by space: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++; 
        
        if (arr[i] == k) {
            found_index = i; 
            break;           
        }
    }

    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }
    
    printf("Comparisons = %d\n", comparisons);

    free(arr);
    return 0;
}