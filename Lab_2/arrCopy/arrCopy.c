#include <stdio.h>
#include <stdlib.h>

int size; // Variable to record size of original array arr
int evenCount = 0,
    oddCount =
        0;     // Variables to record sizes of new arrays arr_even and arr_odd
int *arr;      // Dynamically allocated original array with #elements = size
int *arr_even; // Dynamically allocated array with #elements = #even elements in
               // arr (evenCount)
int *arr_odd;  // Dynamically allocated array with #elements = #odd elements in
               // arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

/*
 * DO NOT change the definition of the printArr function when it comes to
 * adding/removing/modifying the function parameters, or changing its return
 * type.
 */
void printArr(int *a, int size, char *prompt) {
    printf("%s", prompt);
    if (size == 0) {
        printf("empty\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

/*
 * DO NOT change the definition of the arrCopy function when it comes to
 * adding/removing/modifying the function parameters, or changing its return
 * type.
 */
void arrCopy() {
    int evenIdx = 0;
    int oddIdx = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            *(arr_even + evenIdx) = *(arr + i);
            evenIdx++;
        } else {
            *(arr_odd + oddIdx) = *(arr + i);
            oddIdx++;
        }
    }
}

int main() {
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    int input;
    for (int i = 0; i < size; i++) {
        printf("Enter array element #%d: ", i + 1);
        scanf("%d", &input);
        if (input % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
        *(arr + i) = input;
    }
    printf("\n");

    arr_even = (int *)malloc(evenCount * sizeof(int));
    arr_odd = (int *)malloc(oddCount * sizeof(int));

    /*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/

    // Print original array
    printArr(arr, size, str1);

    /// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}
