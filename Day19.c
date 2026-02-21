#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int bestLeft = left, bestRight = right;
    int minSum = abs(arr[left] + arr[right]);

    while (left < right) {
        int sum = arr[left] + arr[right];
        int absSum = abs(sum);

        if (absSum < minSum) {
            minSum = absSum;
            bestLeft = left;
            bestRight = right;
        }

        if (sum < 0)
            left++;        
        else if (sum > 0)
            right--;       
            break;         
    }
    printf("\nPair closest to zero: %d %d\n", arr[bestLeft], arr[bestRight]);
    printf("Their sum: %d\n", arr[bestLeft] + arr[bestRight]);

    return 0;
}
