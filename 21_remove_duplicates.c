#include <stdio.h>

int remove_duplicates(int arr[], int n) {
    if (n <= 1) return n;

    int k = 0;

    for (int i = 0; i < n; i++) {
        int dup = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i] == arr[j]) {
                dup = 1;
                break;
            }
        }

        if (!dup) {
            arr[k++] = arr[i];
        }
    }

    return k;
}

int main(void) {
    int n;

    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size! Must be greater than 0.\n");
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

    int k = remove_duplicates(arr, n);

    printf("\nArray after removing duplicates (New Size = %d):\n[ ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    return 0;
}
