#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main(void) {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	printf("Value of head: %p\n", head);
    printf("Adress of head: %p\n", &head);
    printf("Adress of iValue: %p\n", &head->iValue);
    printf("Adress of fValue: %p\n", &head->fValue);
    printf("Adress of next: %p\n", &head->next);
	
	return 0;
}