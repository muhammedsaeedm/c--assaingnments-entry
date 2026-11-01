#include <stdio.h>
#include <stdlib.h>

void int_to_str(long long n, char *s) {
    int i = 0;
    int neg = 0;

    if (n == 0) {
        s[i++] = '0';
        s[i] = '\0';
        return;
    }

    if (n < 0) {
        neg = 1;
    }

    long long t = llabs(n);
    while (t > 0) {
        s[i++] = (t % 10) + '0';
        t /= 10;
    }

    if (neg) {
        s[i++] = '-';
    }

    s[i] = '\0';

    int l = 0, r = i - 1;
    while (l < r) {
        char ch = s[l];
        s[l] = s[r];
        s[r] = ch;
        l++;
        r--;
    }
}

int main(void) {
    long long n;
    char s[64];

    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) {
        printf("Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    int_to_str(n, s);

    printf("Converted string: \"%s\"\n", s);

    return 0;
}
