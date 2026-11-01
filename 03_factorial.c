#include <stdio.h>

int main(void) {
    int n;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 1;
    }

    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= (unsigned long long)i;
    }

    printf("Factorial of %d (%d!) = %llu\n", n, n, fact);

    return 0;
}
