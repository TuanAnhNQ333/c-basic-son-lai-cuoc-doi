/*
Write a function that gets a string and two chars as arguments. The functions scans the string and replaces every occurrence of the first char with the second one.
Write a program to test the above function. The program should read a string from the user (no spaces) and two characters, then call the function with the input, and print the result.
For example
- input: “papa”, ‘p’, ‘m’
- output: “mama”
*/
#include<stdio.h>
#include<string.h>
#define maxlen 101
int main() {
    char string[maxlen];
    char replace1, replace2;
    scanf("%s %c %c",string, &replace1, &replace2);
    for(int i = 0; i < strlen(string); i ++) {
        if(string[i] == replace1) {
            string[i] = replace2;
        } 
    }
    printf("%s", string);
    return 0;
}