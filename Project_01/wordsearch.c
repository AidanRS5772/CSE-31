#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
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
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
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
    // searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            char c = *(*(arr + i) + j);
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
            printf("%c", c);
            printf(" ");
        }
        printf("\n");
    }
}

void searchPuzzle(char** arr, char* word) {
    char fist_c = *word;
    if (fist_c >= 'a' && fist_c <= 'z') {
        fist_c = fist_c - 'a' + 'A';
    }
    int first_char_cnt = 0;
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            char c = *(*(arr + i) + j);
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
            if ((first_c == ))

            
        }
    }
}
