#include <stdio.h>

int main() {
  int x, y, *px, *py;
  x = 0;
  y = 0;
  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = 0;
  }

  px = &x;
  py = &y;

  printf("*px = %d , px = %p , &x = %p\n", *px, px, &x);
  printf("*py = %d , py = %p , &y = %p\n", *py, py, &y);

  for (int i = 0; i < 10; i++) {
    printf("arr[%d] = %d\n", i, *(arr + i));
  }

  int *a1 = &arr[0];
  printf("arr = %p, a1 = %p\n", arr, a1);

  return 0;
}
