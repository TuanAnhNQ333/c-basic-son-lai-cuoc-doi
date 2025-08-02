#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1001

void text_replacement(char *text, const char *replace_what_T1, const char *replace_with_T2) {
    char buffer[MAX_LEN * 10] = {0}; // Large enough for replacements
    char *pos = text;
    int len_replace_what = strlen(replace_what_T1);
    int len_replace_with = strlen(replace_with_T2);

    while ((pos = strstr(pos, replace_what_T1)) != NULL) {
        strncat(buffer, text, pos - text);
        strcat(buffer, replace_with_T2);
        text = pos + len_replace_what;
        pos = text;
    }
    strcat(buffer, text);
    strncpy(text, buffer, MAX_LEN - 1);
    text[MAX_LEN - 1] = '\0';
}

int main() {
    char replace_what_T1[MAX_LEN];
    char replace_with_T2[MAX_LEN];
    char text[MAX_LEN];

    fgets(replace_what_T1, MAX_LEN, stdin);
    replace_what_T1[strcspn(replace_what_T1, "\n")] = 0;

    fgets(replace_with_T2, MAX_LEN, stdin);
    replace_with_T2[strcspn(replace_with_T2, "\n")] = 0;

    fgets(text, MAX_LEN, stdin);
    text[strcspn(text, "\n")] = 0;

    text_replacement(text, replace_what_T1, replace_with_T2);

    printf("%s\n", text);

    return 0;
}
