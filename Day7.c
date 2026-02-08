#include <stdio.h>
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    printf("Enter position n: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        int result = fib(n);
        printf("Fibonacci number at position %d is: %d\n", n, result);
    }

    return 0;
}