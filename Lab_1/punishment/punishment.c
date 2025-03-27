#include <stdbool.h>
#include <stdio.h>

int main() {
  printf("Enter the repetition count for the punishment phrase: ");
  int count;
  while (true) {
    scanf("%d", &count);
    if (count <= 0) {
      printf("You entered an invalid value for the repetition count! Please "
             "re-enter: ");
    } else {
      break;
    }
  }

  printf("\nEnter the line where you want to insert the typo: ");
  int line;
  while (true) {
    scanf("%d", &line);
    if (line <= 0 || line > count) {
      printf("You entered an invalid value for the typo placement! Please "
             "re-enter: ");
    } else {
      break;
    }
  }
  printf("\n");

  for (int i = 1; i <= count; i++) {
    if (i == line) {
      printf("Cading wiht is C avesone!\n");
    } else {
      printf("Coding with C is awesome!\n");
    }
  }

  return 0;
}
