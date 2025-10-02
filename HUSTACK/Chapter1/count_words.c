/*
Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

Input
The Text

Output
Write the number Q of words

Example
Input
Hanoi University Of Science and Technology
School of Information and Communication Technology


Output
12
*/
#include<stdio.h>
#include<string.h>
#define max_len 20001
int count_word(const char * text) {
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
    return count;
}
int main() {
    char array[max_len];
    int len = 0;

    // đọc toàn bộ input đến EOF
    int c;
    while ((c = getchar()) != EOF && len < max_len - 1) {
        array[len++] = (char)c;
    }
    array[len] = '\0';

    int result = count_word(array);
    printf("%d\n", result);

    return 0;
}