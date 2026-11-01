#include <stdio.h>

int main(void) {
    long long n;

    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) {
        printf("Invalid input! Please enter a valid whole number.\n");
        return 1;
    }

    if (n % 2 == 0) {
        printf("%lld is an EVEN number.\n", n);
    } else {
        printf("%lld is an ODD number.\n", n);
    }

    return 0;
}
