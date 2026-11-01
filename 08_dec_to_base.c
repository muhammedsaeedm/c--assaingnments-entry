#include <stdio.h>

void dec_to_base(long long n, int b, char res[]) {
    if (n == 0) {
        res[0] = '0';
        res[1] = '\0';
        return;
    }

    char temp[65];
    int k = 0;

    while (n > 0) {
        int r = n % b;
        if (r < 10) {
            temp[k++] = '0' + r;
        } else {
            temp[k++] = 'A' + (r - 10);
        }
        n /= b;
    }

    int j = 0;
    for (int i = k - 1; i >= 0; i--) {
        res[j++] = temp[i];
    }
    res[j] = '\0';
}

int main(void) {
    long long n;
    int b;
    char res[65];

    printf("Enter a non-negative decimal number: ");
    if (scanf("%lld", &n) != 1 || n < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Enter target base (2 - 16): ");
    if (scanf("%d", &b) != 1 || b < 2 || b > 16) {
        printf("Invalid base! Base must be between 2 and 16.\n");
        return 1;
    }

    dec_to_base(n, b, res);

    printf("Decimal %lld in base %d is: %s\n", n, b, res);

    return 0;
}
