#include <stdio.h>

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(void) {
    long long a, b;

    printf("Enter two positive integers: ");
    if (scanf("%lld %lld", &a, &b) != 2 || a <= 0 || b <= 0) {
        printf("Invalid input! Please enter two positive integers greater than 0.\n");
        return 1;
    }

    long long res = gcd(a, b);

    printf("GCD of %lld and %lld is: %lld\n", a, b, res);

    return 0;
}
