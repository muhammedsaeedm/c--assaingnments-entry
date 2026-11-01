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

    printf("Enter first integer (num1): ");
    if (scanf("%u", &a) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter second integer (num2): ");
    if (scanf("%u", &b) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter starting bit position (0 to 31): ");
    if (scanf("%d", &pos) != 1 || pos < 0 || pos > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return 1;
    }

    printf("Enter number of bits to swap (n): ");
    if (scanf("%d", &k) != 1 || k <= 0 || pos + k > 32) {
        printf("Invalid number of bits! (pos + n) must not exceed 32.\n");
        return 1;
    }

    unsigned int n_mask = (k == 32) ? 0xFFFFFFFFU : ((1U << k) - 1);
    unsigned int mask = n_mask << pos;

    printf("\n--- BEFORE SWAP ---");
    printf("\nNum1:  %u (Hex: 0x%X)\nBinary: ", a, a);
    print_bin(a);
    printf("\nNum2:  %u (Hex: 0x%X)\nBinary: ", b, b);
    print_bin(b);

    unsigned int b1 = a & mask;
    unsigned int b2 = b & mask;

    a = (a & ~mask) | b2;
    b = (b & ~mask) | b1;

    printf("\n\n--- AFTER SWAP ---");
    printf("\nNum1:  %u (Hex: 0x%X)\nBinary: ", a, a);
    print_bin(a);
    printf("\nNum2:  %u (Hex: 0x%X)\nBinary: ", b, b);
    print_bin(b);
    printf("\n");

    return 0;
}
