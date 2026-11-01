#include <stdio.h>

int is_perfect(long long n) {
    if (n <= 1) {
        return 0;
    }

    long long sum = 1;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            long long d = n / i;
            if (d != i && d != n) {
                sum += d;
            }
        }
    }

    return (sum == n);
}

int main(void) {
    long long n;

    printf("Enter a positive integer: ");
    if (scanf("%lld", &n) != 1 || n <= 0) {
        printf("Invalid input! Please enter a positive integer greater than 0.\n");
        return 1;
    }

    if (is_perfect(n)) {
        printf("%lld is a PERFECT NUMBER.\n", n);
    } else {
        printf("%lld is NOT a perfect number.\n", n);
    }

    return 0;
}
