#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;
size_t wrd_len;

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
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            char c = *(*(arr + i) + j);
            printf("%c", c);
            printf(" ");
        }
        printf("\n");
    }
}

void upper(char* c){
    if (*c >= 'a' && *c <= 'z') {
        *c -= 32;
    }
}

int intlog_10(int num){
    int out = 0;
    while (num >= 10){
        num /= 10;
        out++;
    }
    return out;
}

bool DFS(char** arr, char* word, int** path, size_t wrd_idx, int row, int col){
    if (wrd_idx == wrd_len){
        return true;
    }

    char wrd_char = *(word + wrd_idx);
    upper(&wrd_char);

    for(int i=-1; i <= 1; i++){
        for(int j=-1; j <= 1; j++){
            if (i == 0 && j == 0) continue;
            int newRow = row + i;
            int newCol = col + j;
            if (newRow < 0 || newRow >= bSize || newCol < 0 || newCol >= bSize) continue;

            char grid_char = *(*(arr+newRow)+newCol);

            if (wrd_char == grid_char) {
                *(*(path+newRow)+newCol) *= 10;
                *(*(path+newRow)+newCol) += wrd_idx+1;
                if (DFS(arr, word, path, wrd_idx+1, newRow, newCol)) {
                    return true;
                }
            }
        }
    }
    *(*(path+row)+col) /= 10;

    return false;
}

void searchPuzzle(char** arr, char* word) {
    wrd_len = strlen(word);
    char c = *word;
    upper(&c);

    int** path = (int**)malloc(bSize*sizeof(int*));
    for(int i = 0; i < bSize; i++){
        *(path + i) = (int*)malloc(bSize*sizeof(int));
        for(int j = 0; j < bSize; j++){
            *(*(path+i)+j) = 0;
        }
    }

    bool found = false;
    for(int i = 0; i < bSize; i++){
        for(int j = 0; j < bSize; j++){
            if (*(*(arr + i)+j) == c){
                *(*(path+i)+j) = 1;
                if (DFS(arr, word, path, 1, i, j)){
                    found = true;
                }
            }
        }
    }

    
    if (found){
        printf("\nWord Found!\n");
        printf("Printing the search path:\n");
        for (int i = 0; i < bSize; i++) {
            for (int j = 0; j < bSize; j++) {
                int val = *(*(path + i) + j);
                int num_dig = intlog_10(val);
                printf("%d", val);
                for(int k=0; k<(5-num_dig); k++){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }else{
        printf("\nWord Not Found!\n");
    }

    for (int i = 0; i < bSize; i++) {
        free(path[i]);
    }
    free(path);
}
