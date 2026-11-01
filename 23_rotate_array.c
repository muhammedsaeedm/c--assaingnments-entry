#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(int arr[], int l, int r) {
    while (l < r) {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

void rotate_left(int arr[], int n, int k) {
    k = k % n;
    if (k == 0) return;

    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

void rotate_right(int arr[], int n, int k) {
    k = k % n;
    if (k == 0) return;

    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}

int main(void) {
    int n, k;
    char dir[16];

    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid element input!\n");
            return 1;
        }
    }

    printf("Enter number of positions to rotate: ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid rotation step count!\n");
        return 1;
    }

    printf("Enter direction (left or right): ");
    if (scanf("%15s", dir) != 1) {
        printf("Invalid direction!\n");
        return 1;
    }

    for (int i = 0; dir[i] != '\0'; i++) {
        dir[i] = (char)tolower((unsigned char)dir[i]);
    }

    if (strcmp(dir, "left") == 0) {
        rotate_left(arr, n, k);
    } else if (strcmp(dir, "right") == 0) {
        rotate_right(arr, n, k);
    } else {
        printf("Unsupported direction '%s'. Please enter 'left' or 'right'.\n", dir);
        return 1;
    }

    printf("\nRotated Array:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    return 0;
}
