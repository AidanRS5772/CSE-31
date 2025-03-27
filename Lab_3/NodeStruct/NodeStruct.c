#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;

    printf("head value: %p\n", head);
    printf("head adress: %p\n", &head);
    printf("iValue adress: %p\n", &(head->iValue));
    printf("fValue adress: %p\n", &(head->fValue));
    printf("next adress: %p\n", &(head->next));
    return 0;
}
