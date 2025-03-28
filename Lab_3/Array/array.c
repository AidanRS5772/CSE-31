#include <stdio.h>
#include <stdlib.h>

int *bubbleSort(int arr[], int n) {
    int temp, i = 0, j = 0;
    int *s_arr = (int *)malloc(n * sizeof(int));

    // Copy arr to s_arr
    for (i = 0; i < n; i++)
        s_arr[i] = arr[i];

    // Sorting using array notations
    // Comment this when implementing pointer version.
    // for (i = 0; i < n - 1; i++) {
    //     for (j = 0; j < n - 1; j++) {
    //         if (s_arr[j] > s_arr[j + 1]) {
    //             temp = s_arr[j + 1];
    //             s_arr[j + 1] = s_arr[j];
    //             s_arr[j] = temp;
    //         }
    //     }
    // }

    // Sorting using pointer notations. i.e. you cannot use "[]"!
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (*(s_arr + j) > *(s_arr + j + 1)) {
                temp = *(s_arr + j + 1);
                *(s_arr + j + 1) = *(s_arr + j);
                *(s_arr + j) = temp;
            }
        }
    }

    return s_arr;
}

void printArray(int arr[], int n) {
    int i = 0;
    printf("[");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int bSearch(int *arr, int a, int b, int key) {
    if (a > b)
        return -1;

    int m = (a + b) / 2;

    if (*(arr + m) == key)
        return m;
    else if (*(arr + m) < key)
        return bSearch(arr, m + 1, b, key);
    else
        return bSearch(arr, a, m - 1, key);
}

int main() {

    int i = 0, size = 0, key = 0, result = 0;
    int *array, *sorted;

    printf("How big is your array? ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        printf("Please enter array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Please wait while I sort your numbers...\n");
    sorted = bubbleSort(array, size);
    printf("Here is your original array:\n");
    printArray(array, size);
    printf("Here is your SORTED array: \n");
    printArray(sorted, size);
    printf("What number are you looking for? ");
    scanf("%d", &key);
    printf("OK, let me see if I can find a \"%d\" in the array...\n", key);
    result = bSearch(sorted, 0, size - 1, key);
    if (result != -1)
        printf("Got it! A \"%d\" is at index %d.\n", key, result);
    else
        printf("I'm sorry, \"%d\" cannot be found in the array.\n", key);

    return 0;
}
