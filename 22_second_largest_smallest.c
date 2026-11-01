#include <stdio.h>
#include <limits.h>

int main(void) {
    int n;

    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size! Must be greater than 0.\n");
        return 1;
    }

    if (n < 2) {
        printf("Array must have at least 2 elements.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input!\n");
            return 1;
        }
    }

    int min1 = arr[0], max1 = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min1) min1 = arr[i];
        if (arr[i] > max1) max1 = arr[i];
    }

    if (min1 == max1) {
        printf("\nAll elements in the array are identical (%d).\n", min1);
        printf("Neither a distinct second largest nor second smallest element exists.\n");
        return 0;
    }

    int min2 = INT_MAX, max2 = INT_MIN;
    int has_min2 = 0, has_max2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > min1 && arr[i] <= min2) {
            min2 = arr[i];
            has_min2 = 1;
        }
        if (arr[i] < max1 && arr[i] >= max2) {
            max2 = arr[i];
            has_max2 = 1;
        }
    }

    printf("\nSmallest: %d | Largest: %d\n", min1, max1);

    if (has_min2) {
        printf("Second Smallest: %d\n", min2);
    } else {
        printf("Second Smallest: Not found\n");
    }

    if (has_max2) {
        printf("Second Largest:  %d\n", max2);
    } else {
        printf("Second Largest:  Not found\n");
    }

    return 0;
}
