#include <stdio.h>

void merge_sorted(const int a[], int n1, const int b[], int n2, int res[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }

    while (i < n1) {
        res[k++] = a[i++];
    }

    while (j < n2) {
        res[k++] = b[j++];
    }
}

int main(void) {
    int n1, n2;

    printf("Enter size of first sorted array: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) {
        printf("Invalid size for first array!\n");
        return 1;
    }

    int a[n1 > 0 ? n1 : 1];
    if (n1 > 0) {
        printf("Enter %d sorted elements for first array:\n", n1);
        for (int i = 0; i < n1; i++) {
            if (scanf("%d", &a[i]) != 1) {
                printf("Invalid input element!\n");
                return 1;
            }
        }
    }

    printf("Enter size of second sorted array: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) {
        printf("Invalid size for second array!\n");
        return 1;
    }

    int b[n2 > 0 ? n2 : 1];
    if (n2 > 0) {
        printf("Enter %d sorted elements for second array:\n", n2);
        for (int i = 0; i < n2; i++) {
            if (scanf("%d", &b[i]) != 1) {
                printf("Invalid input element!\n");
                return 1;
            }
        }
    }

    int tot = n1 + n2;
    int res[tot > 0 ? tot : 1];

    merge_sorted(a, n1, b, n2, res);

    printf("\nMerged Sorted Array (%d elements):\n[ ", tot);
    for (int i = 0; i < tot; i++) {
        printf("%d ", res[i]);
    }
    printf("]\n");

    return 0;
}
