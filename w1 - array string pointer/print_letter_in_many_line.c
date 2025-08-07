#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100
void print_letter_in_many_line(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            printf("\n");
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}
int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    
    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    print_letter_in_many_line(str);
    return 0;
}