#include <stdio.h>

int main(void) {
    int rep_cnt;
    printf("\nEnter the repetition count for the punishment phrase: ");
    scanf("%d", &rep_cnt);
    printf("\n");

    while (rep_cnt <= 0) {
        printf("You entered an invalid value for the repetition count! Please re-enter: ");
        scanf("%d", &rep_cnt);
    }

    int err_ln;
    printf("Enter the line where you want to insert the typo: ");
    scanf("%d", &err_ln);
    printf("\n");

    while ((err_ln <= 0) || (err_ln > rep_cnt)) {
        printf("You entered an invalid value for the typo placement! Please re-enter: ");
        scanf("%d", &err_ln);
    }

    char *str = "Coding with C is awesome!\n";
    char *err_str = "Cading wiht is C avesone!\n";

    for (int i = 1; i <= rep_cnt; i++) {
        if (i == err_ln) {
            printf("%s", err_str);
            continue;
        }
        printf("%s", str);
    }

    return 0;
}
