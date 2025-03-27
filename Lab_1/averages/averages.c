#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int cnt = 1;
  int even_cnt = 0;
  int odd_cnt = 0;
  int even_sum = 0;
  int odd_sum = 0;
  int input;
  while (true) {
    printf("Enter the %d", cnt);
    if (cnt / 10 % 10 != 1) {
      if (cnt % 10 == 1) {
        printf("st value: ");
      } else if (cnt % 10 == 2) {
        printf("nd value: ");
      } else if (cnt % 10 == 3) {
        printf("rd value: ");
      } else {
        printf("th value: ");
      }
    } else {
      printf("th value: ");
    }

    scanf("%d", &input);
    if (input == 0) {
      break;
    }

    int tmp = abs(input);
    int digit_sum = 0;
    while (tmp > 0) {
      digit_sum += tmp % 10;
      tmp /= 10;
    }

    if (digit_sum % 2 == 0) {
      even_cnt++;
      even_sum += input;
    } else {
      odd_cnt++;
      odd_sum += input;
    }

    cnt++;
  }
  printf("\n");

  if (cnt == 1) {
    printf("There is no average to compute.\n");
    return 0;
  }

  if (even_cnt > 0) {
    printf("\nAverage of input values whose digits sum up to an even number: "
           "%.2f\n",
           (float)even_sum / (float)even_cnt);
  }

  if (odd_cnt > 0) {
    printf(
        "Average of input values whose digits sum up to an odd number: %.2f\n",
        (float)odd_sum / (float)odd_cnt);
  }

  return 0;
}
