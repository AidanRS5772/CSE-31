#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char **arr);
void searchPuzzle(char **arr, char *word);
int bSize;

// Main function, DO NOT MODIFY
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);

    // Allocate space for the puzzle block and the word to be searched
    char **block = (char **)malloc(bSize * sizeof(char *));
    char *word = (char *)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for (i = 0; i < bSize; i++) {
        *(block + i) = (char *)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);

    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);

    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);

    return 0;
}

void printPuzzle(char **arr) {
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            printf("%c ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

char upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

bool DFS(char **arr, char *word, unsigned int **tracker, int word_idx, int row, int col) {
    if (*(*(arr + row) + col) != upper(*(word + word_idx))) return false;

    *(*(tracker + row) + col) *= 10;
    *(*(tracker + row) + col) += word_idx + 1;

    if (word_idx == strlen(word) - 1) return true;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (row + i < 0 || row + i >= bSize || col + j < 0 || col + j >= bSize) continue;
            if (DFS(arr, word, tracker, word_idx + 1, row + i, col + j)) return true;
        }
    }

    *(*(tracker + row) + col) /= 10;
    return false;
}

void searchPuzzle(char **arr, char *word) {
    unsigned int **tracker = (unsigned int **)malloc(bSize * sizeof(unsigned int *));
    for (int i = 0; i < bSize; i++) {
        *(tracker + i) = (unsigned int *)malloc(bSize * sizeof(unsigned int));
        for (int j = 0; j < bSize; j++) {
            *(*(tracker + i) + j) = 0;
        }
    }

    bool found = false;
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if (DFS(arr, word, tracker, 0, i, j)) found = true;
        }
    }

    if (!found) {
        printf("Word not found!\n");
    } else {
        printf("Word found!\n");
        for (int i = 0; i < bSize; i++) {
            for (int j = 0; j < bSize; j++) {
                printf("%-4d", *(*(tracker + i) + j));
            }
            printf("\n");
        }
    }

    for (int i = 0; i < bSize; i++) {
        free(*(tracker + i));
    }
    free(tracker);
}
