
#include <stdio.h>
#include <stdlib.h>

int **matMult(int **a, int **b, int size) {
    // (4) Implement your matrix multiplication here.
    int** mat = (int**)malloc(size * sizeof(int*));
	for(int i = 0; i < size; i++){
		*(mat + i) = (int*)malloc(size * sizeof(int));
		for(int j=0; j < size; j++){
			int val = 0;
			for(int k=0; k < size; k++){
				val += (*(*(a+i)+k))*(*(*(b+k)+j));
			}
			*(*(mat+i)+j) = val;
		}
	}

	return mat;
}

void printArray(int **arr, int n) {
    // (2) Implement your printArray function here
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int n = 3;
    int **matA, **matB, **matC;

    // (1) Define 2 (n x n) arrays (matrices).
    matA = (int **)malloc(n * sizeof(int *));
    matB = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(matA + i) = (int *)malloc(n * sizeof(int));
        *(matB + i) = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            *(*(matA + i) + j) = i + j;
            *(*(matB + i) + j) = (i+1) * (j+1);
        }
    }

    // (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printArray(matB, n);

    // (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);

    // (6) Call printArray to print out resulting array here.
	printArray(matC, n);

    return 0;
}
