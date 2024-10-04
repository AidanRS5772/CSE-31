#include <stdio.h>
#include <stdlib.h>

 int main(void) {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *) malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **) malloc(1 * sizeof(int *));
	*handle = ptr;

	printf("num adr: %p\n", &num);
	printf("ptr adr: %p\n", &ptr);
	printf("ptr val: %p\n", ptr);
	printf("handle adr: %p\n", &handle);
	printf("handle val: %p\n", handle);
	printf("handle dref: %p\n", *handle);

	return 0;
} 

