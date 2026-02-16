#include <stdio.h>
int main() {
    int n;
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;  
    }
    
    printf("\nFrequency of elements:\n");
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }
        
        int count = 1;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  
            }
        }
        
        printf("%d:%d ", arr[i], count);
    }
    
    printf("\n");
    
    return 0;
}