#include <stdbool.h>
#include <stdio.h>

static const int size = 10;

void printArray(int arr[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int p = arr[h];
        int i = l;
        int j = h - 1;
        while (i <= j) {
            while (arr[i] < p) {
                i++;
            }
            while (arr[j] > p) {
                j--;
            }
            if (i < j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }
        swap(&arr[i], &arr[h]);
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, h);
    }
}

int main() {
    int arr[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    printArray(arr);
    quickSort(arr, 0, size - 1);
    printArray(arr);
    return 0;
}
