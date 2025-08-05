#include <stdio.h>

void replace_char(char *str, char c1, char c2) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c1) {
            str[i] = c2;
        }
    }
}

int main() {
    char s[] = "hello world";
    replace_char(s, 'o', 'a');
    printf("%s\n", s); // Kết quả: "hella warld"
    return 0;
}




