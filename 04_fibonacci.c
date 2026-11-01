#include <stdio.h>

int main(void) {
    int n;

    printf("Enter the number of terms (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 0;
    }

    unsigned long long a = 0, b = 1, c;

    printf("Fibonacci Series (%d terms): \n", n);

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%llu", a);
        } else if (i == 2) {
            printf(", %llu", b);
        } else {
            c = a + b;
            a = b;
            b = c;
            printf(", %llu", c);
        }
    }
    printf("\n");

    return 0;
}
