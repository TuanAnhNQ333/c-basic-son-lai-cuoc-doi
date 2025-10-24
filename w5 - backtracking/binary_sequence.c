/*
Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line
Example
Input
3
Output
000
001
010
100
101
*/
#include<stdio.h>
#include<math.h>
#define N 20
int n; 
int x[N];

void print_solution() {
    for(int i = 0; i < n; i ++) {
        printf("%d", x[i]);
    }
    printf("\n");
}
void try(int k) {
    for (int v = 0; v <= 1; v++) {
        // điều kiện: không cho "11" liên tiếp
        if (k > 0 && x[k-1] == 1 && v == 1) continue;

        x[k] = v;
        if (k == n - 1) print_solution();
        else try(k + 1);
    }
}
int main() {
    scanf("%d", &n);
    try(0);
    return 0;
}