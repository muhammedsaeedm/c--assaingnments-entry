#include <stdio.h>

void rearrange(int arr[], int n) {
    if (n <= 1) return;

    int temp[n];
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            temp[k++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            temp[k++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main(void) {
    int n;

    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers (positive, negative, and zeros):\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input!\n");
            return 1;
        }
    }

    printf("\nOriginal Array:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    rearrange(arr, n);

    printf("Rearranged Array (Order Preserved: Negatives First, Non-Negatives Later):\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    return 0;
}
