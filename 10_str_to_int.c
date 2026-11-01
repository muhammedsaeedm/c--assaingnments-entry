#include <stdio.h>

int str_to_int(const char *s, long long *val) {
    if (s == NULL || *s == '\0') {
        return 0;
    }

    long long res = 0;
    int i = 0;
    int sign = 1;

    if (s[i] == '+') {
        i++;
    } else if (s[i] == '-') {
        sign = -1;
        i++;
    }

    if (s[i] == '\0') {
        return 0;
    }

    for (; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
        res = res * 10 + (s[i] - '0');
    }

    *val = res * sign;
    return 1;
}

int main(void) {
    char s[100];
    long long n;

    printf("Enter a number as a string of digits: ");
    if (scanf("%99s", s) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    if (str_to_int(s, &n)) {
        printf("Successfully converted to integer: %lld\n", n);
        printf("Verification (Value + 10): %lld\n", n + 10);
    } else {
        printf("Invalid input! The string contains non-digit characters.\n");
    }

    return 0;
}
