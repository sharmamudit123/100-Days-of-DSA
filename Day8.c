#include <stdio.h>

long long power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    
    return base * power(base, exp - 1);
}

int main() {
    int a, b;

    printf("Enter base (a): ");
    if (scanf("%d", &a) != 1) return 1;

    printf("Enter exponent (b): ");
    if (scanf("%d", &b) != 1) return 1;

    if (b < 0) {
        printf("Exponent should be non-negative for this basic program.\n");
    } else {
        long long result = power(a, b);
        printf("%d^%d = %lld\n", a, b, result);
    }

    return 0;
}