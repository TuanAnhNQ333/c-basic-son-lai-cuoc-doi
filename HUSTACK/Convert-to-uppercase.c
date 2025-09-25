/*Mô tả
Given a TEXT, write a program that converts the TEXT to upper-case. 

Input
The TEXT

Output
The TEXT in which characters are converted into upper-case

Example 
Input 
Hello John,
How are you?

Bye,

Output 
HELLO JOHN,
HOW ARE YOU?

BYE, 

fgets(*file, sizeof(file), stdin);*/
#include<stdio.h>
#include<string.h>

char str[1000] = {0};

int main() {
    
    while(fgets(str, sizeof(str), stdin) != NULL) {
        for(int i = 0; str[i] != '\0'; i ++) {
            if('a' <= str[i] && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
        printf("%s", str);
    }
    return 0;  
}
