#include <stdio.h>

void print_bin(unsigned int val) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" ");
    }
}

int main(void) {
    unsigned int a, b;
    int pos, k;

    printf("Enter first integer (destination): ");
    if (scanf("%u", &a) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter second integer (source): ");
    if (scanf("%u", &b) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter starting bit position (0 to 31): ");
    if (scanf("%d", &pos) != 1 || pos < 0 || pos > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return 1;
    }

    printf("Enter number of bits to replace (n): ");
    if (scanf("%d", &k) != 1 || k <= 0 || pos + k > 32) {
        printf("Invalid number of bits! (pos + n) must not exceed 32.\n");
        return 1;
    }

    unsigned int n_mask = (k == 32) ? 0xFFFFFFFFU : ((1U << k) - 1);
    unsigned int mask = n_mask << pos;

    unsigned int res = (a & ~mask) | (b & mask);

    printf("\nFirst Number:       %u (Hex: 0x%X)\nBinary:             ", a, a);
    print_bin(a);
    printf("\nSecond Number:      %u (Hex: 0x%X)\nBinary:             ", b, b);
    print_bin(b);
    printf("\nMask at pos %2d:     (Hex: 0x%X)\nBinary:             ", pos, mask);
    print_bin(mask);
    printf("\nResulting Number:   %u (Hex: 0x%X)\nBinary:             ", res, res);
    print_bin(res);
    printf("\n");

    return 0;
}
