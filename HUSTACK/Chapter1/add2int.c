/*
Compute the sum of two integers a and b.
Input
Line 1 contains two integers a and b (0 <= a, b <= 10
19
)
Ouput
Write the sum of a and b
Example
Input
3 5
Output
8*/
#include<stdio.h>
#include<string.h>

int main() {
    char a[1000];
    char b[1000];
    char result[1000];
    int i,j;
    int k = 0;
    int carry = 0;
    scanf("%s", a);
    scanf("%s", b);
    i = strlen(a) - 1;
    j = strlen(b) - 1; 
    while(i >= 0 || j >= 0 || carry > 0) {
        int digitA = 0;
        int digitB = 0;
        if(i >= 0) {
            digitA = a[i] - '0';
            i --;
        }
        if(j >= 0) {
            digitB = b[j] - '0';
            j --;
        }
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        int digit = sum % 10;
        result[k] = digit + '0';
        k ++;

    }
    result[k] = '\0';
    // reverse result 
    for( i = 0, j = k - 1; i < j; i ++, j --) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    printf("%s", result);
    return 0;
}