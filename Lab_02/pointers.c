#include <stdio.h>

int main() {
    int x = 0, y = 0, *px, *py;
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    px = &x;
    py = &y;

    printf("x adress: %p \n", &x);
    printf("px value: %p \n", px);
    printf("px adress: %p \n", &px);
    printf("y adress: %p \n", &y);
    printf("py value: %p \n", py);
    printf("py adress: %p \n", &py);
    
    for(int i=0; i < 10; i++){
        printf("arr[%d] value: %d \n", i, *(arr+i));
    }

    if(&arr[0] == arr){
        printf("Yes they are the same.\n");
        printf("arr[0] adress: %p \n", &arr[0]);
        printf("arr value: %p \n", arr);
    }
    return 0;
}