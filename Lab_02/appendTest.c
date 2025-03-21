#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Return the result of appending the characters in s2 to s1.
 * Assumption: enough space has been allocated for s1 to store the extra
 * characters.
 */

/*
 * DO NOT change the definition of the append function when it comes to
 * adding/removing/modifying the function parameters, or changing its return
 * type. You may, however, modify the body of the function if you wish.
 */
char *append(char s1[], char s2[]) {
  int s1len = strlen(s1);
  int s2len = strlen(s2);
  char *word = (char *)malloc((s1len + s2len+1) * sizeof(char));
  for (int k = 0; k < s1len; k++) {
    *(word+k) = *(s1+k);
  }
  for (int k = 0; k < s2len; k++) {
    *(word + k + s1len) = *(s2+k);
  }
  *(word + s1len + s2len) = '\0';
  return word;
}

/*
 * DO NOT MODIFY unless when you run this, your code fails to grab input with
 * spaces, in which case, comment the lines with the scanf and uncomment the
 * line below them to fix this problem.
 */
int main(void) {
  char str1[10];
  char str2[10];
  while (1) {
    printf("str1 = ");
    scanf("%[^\n]%*c", str1);
    // if (!gets(str1)) return 0;
    printf("str2 = ");
    scanf("%[^\n]%*c", str2);
    // if (!gets(str2)) return 0;

    printf("The result of appending str2 to str1 is %s.\n", append(str1, str2));
    fflush(stdin);
  }
  return 0;
}
