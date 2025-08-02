#include <stdio.h>
#include <stdlib.h>

#define STRING_LEN 100
void replace(char str[], char replace_what, char replace_with) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == replace_what) {
            str[i] = replace_with;
        }
    }
}
int main(void) {
    char str[STRING_LEN];
    char replace_what, replace_with, tmp;

    printf("Enter a string: ");
    scanf("%100s", str);

    printf("Letters to replace: ");
    scanf(" %c", &replace_what);
    do{
        tmp = getchar();
    } while (tmp != '\n');
    printf("Replace with: ");
    scanf(" %c", &replace_with);

    replace(str, replace_what, replace_with);
    printf("Modified string: %s\n", str);
    return 0;
}

