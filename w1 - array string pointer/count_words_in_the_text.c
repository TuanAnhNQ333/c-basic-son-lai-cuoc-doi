#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 1000
void count_words_in_text(const char * text) {
    int count = 0;
    int in_word = 0;

    for(int i = 0; text[i] != '\0'; i ++) {
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            if(in_word) {
                in_word = 0;
            }
            else {
                continue;
            }
        }
        else {
            if(!in_word) {
                in_word = 1;
                count++;
            }
        }
    }
    printf("%d", count);
}
int main() {
    char text[MAX_LEN];
    fgets(text, MAX_LEN, stdin);
    
    // Remove newline character if present
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    count_words_in_text(text);
    return 0;
}
