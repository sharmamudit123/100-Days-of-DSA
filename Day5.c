#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;

    printf("Enter number of entries in log 1: ");
    if (scanf("%d", &p) != 1) return 1;

    int *log1 = (int*)malloc(p * sizeof(int));
    printf("Enter %d sorted arrival times for log 1: ", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    printf("Enter number of entries in log 2: ");
    if (scanf("%d", &q) != 1) return 1;

    int *log2 = (int*)malloc(q * sizeof(int));
    printf("Enter %d sorted arrival times for log 2: ", q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    printf("Chronological Log: ");
    int i = 0, j = 0;

    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }
    printf("\n");

    free(log1);
    free(log2);

    return 0;
}