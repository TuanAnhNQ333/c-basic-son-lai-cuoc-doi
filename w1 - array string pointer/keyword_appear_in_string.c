#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count[26] = {0};

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Loại bỏ ký tự newline

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            count[str[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("The letter '%c'appears in %d time\n", 'a' + i, count[i]);
        }
    }

    return 0;
}