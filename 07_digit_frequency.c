#include <stdio.h>
#include <stdlib.h>

void count_freq(long long n, int *freq) {
    if (n == 0) {
        freq[0]++;
        return;
    }

    long long t = llabs(n);

    while (t > 0) {
        int d = t % 10;
        freq[d]++;
        t /= 10;
    }
}

int main(void) {
    long long n;
    int freq[10] = {0};

    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) {
        printf("Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    count_freq(n, freq);

    printf("\nDigit Frequency in %lld:\n", n);
    printf("------------------------\n");
    printf("Digit | Frequency\n");
    printf("------------------------\n");
    for (int i = 0; i < 10; i++) {
        if (freq[i] > 0) {
            printf("  %d   |    %d\n", i, freq[i]);
        }
    }
    printf("------------------------\n");

    return 0;
}
