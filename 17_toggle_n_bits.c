#include <stdio.h>

void print_bin(unsigned int val) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" ");
    }
}

int main(void) {
    unsigned int n;
    int pos, k;

    printf("Enter an integer: ");
    if (scanf("%u", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter starting bit position (0 to 31, where 0 is LSB): ");
    if (scanf("%d", &pos) != 1 || pos < 0 || pos > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return 1;
    }

    printf("Enter number of bits to toggle (n): ");
    if (scanf("%d", &k) != 1 || k <= 0 || pos + k > 32) {
        printf("Invalid number of bits! (pos + n) must not exceed 32.\n");
        return 1;
    }

    unsigned int mask = 0;
    for (int i = 0; i < k; i++) {
        mask |= (1U << (pos + i));
    }

    unsigned int res = n ^ mask;

    printf("\nOriginal Number: %u (Hex: 0x%X)\nBinary:  ", n, n);
    print_bin(n);
    printf("\nMask:             (Hex: 0x%X)\nBinary:  ", mask);
    print_bin(mask);
    printf("\nToggled Result:  %u (Hex: 0x%X)\nBinary:  ", res, res);
    print_bin(res);
    printf("\n");

    return 0;
}
