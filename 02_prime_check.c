#include <stdio.h>

int main(void) {
    long long n;

    printf("Enter a number to check if it is prime: ");
    if (scanf("%lld", &n) != 1) {
        printf("Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    if (n <= 1) {
        printf("%lld is NOT a prime number (prime numbers must be greater than 1).\n", n);
        return 0;
    }

    int flag = 1;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("%lld is a PRIME number.\n", n);
    } else {
        printf("%lld is NOT a prime number.\n", n);
    }

    return 0;
}
