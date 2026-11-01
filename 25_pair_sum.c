#include <stdio.h>

int main(void) {
    int n;

    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input element!\n");
            return 1;
        }
    }

    int target;
    printf("Enter target sum: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target sum!\n");
        return 1;
    }

    int found = 0;
    printf("\nPairs with sum = %d:\n", target);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("  (%d, %d) at indices [%d, %d]\n", arr[i], arr[j], i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("  No pair of elements found whose sum equals %d.\n", target);
    }

    return 0;
}
