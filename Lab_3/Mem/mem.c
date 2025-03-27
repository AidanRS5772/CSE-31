#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int *ptr;
    int **handle;

    num = 14;
    ptr = (int *)malloc(2 * sizeof(int));
    *ptr = num;
    handle = (int **)malloc(1 * sizeof(int *));
    *handle = ptr;

    printf("&num: %p\n", &num);
    printf("num: %d\n", num);
    printf("&ptr: %p\n", &ptr);
    printf("ptr: %p\n", ptr);
    printf("*ptr: %d\n", *ptr);
    printf("&handle: %p\n", &handle);
    printf("handle: %p\n", handle);
    printf("*handle: %p\n", *handle);
    printf("**handle: %d\n", **handle);

    return 0;
}
