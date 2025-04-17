#include <stdio.h>

int m = 10, n = 5;

int sum(int a, int b) {
    return a + b;
}

int main() {
    int result = sum(m, n);
    printf("%d", result);
    return 0;
}
