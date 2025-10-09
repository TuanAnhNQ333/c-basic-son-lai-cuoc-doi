/*
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line

Example
Input
3
Output
000
001
010
011
100
101
110
111 2^a[2] + 2^a[1] + 2^a[0]
*/
#include<stdio.h>
#include<math.h>
void convert_to_binary(int x, int n) {
    int bit[n];
    for(int i = n-1; i >= 0; i --) {
        bit[i] = x % 2;
        x = x / 2;
    }
    for(int i = 0; i < n; i ++) {
        printf("%d", bit[i]);
    }
    printf("\n");
}
int main() {
    int n; 
    scanf("%d", &n); 

    int total = pow(2, n);
    for(int i = 0; i < total; i ++) {
        convert_to_binary(i, n);
    }
    return 0;


}