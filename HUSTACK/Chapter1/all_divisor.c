/*
Chapter 1 - Find all divisor of an integer
Mô tả
Given a positive integer n, find the sequence of (in creasing order) integers q such that n divides q.
Input
Line 1 contains a positive integer n (1 <= n <= 1000000)

Output
The sequence of integers q described above 

Example
Input
6

Output 
-6 -3 -2 -1  1  2 3  6 
*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for(int i = n; i > 0; i --) {
        if(n % i == 0) {
            printf("-%d ", i);
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(n % i == 0) {
            printf("%d ", i);
        }
    }
    return 0;
}