#include <stdbool.h>
#include <stdio.h>

int main() {
    int val, even_sum = 0, odd_sum = 0;
    while (1) {
        printf("Please enter a number: ");
        scanf("%d", &val);
        if (val == 0) break;
        if (val == (val >> 1) << 1) {
            even_sum += val;
        } else {
            odd_sum += val;
        }
    }
    printf("\nSum of even numbers is: %d\n", even_sum);
    printf("Sum of even numbers is: %d\n", odd_sum);
}
