/*
Given two integer n and M. Write a program that generates all ordered collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M
Input
Line 1: contains 2 integers n and M (2 <= n <= 10, 1 <= M <= 20)
Output
Write in each line X1, X2, ..., Xn separated by a SPACE character
Example
Input
3  5
Output
1 1 3
1 2 2
1 3 1
2 1 2
2 2 1
3 1 1
*/
#include <stdio.h>
#define MAX_N 10

int n, M;
int x[MAX_N + 1];

void print_solution() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// k: current position (1-based), sum: current accumulated sum
void backtrack(int k, int sum) {
    if (k > n) {
        if (sum == M) {
            print_solution();
        }
        return;
    }
    // At the last variable, force the sum to be exactly M
    if (k == n) {
        if (sum + 1 <= M) {
            x[k] = M - sum;
            // Only positive value allowed
            if (x[k] > 0)
                print_solution();
        }
        return;
    }
    // Try all values for x[k] from 1 up to the largest possible so sum+x[k] <= M and (at least 1 for every next)
    for (int v = 1; v <= M - sum - (n - k); v++) {
        x[k] = v;
        backtrack(k + 1, sum + v);
    }
}

int main() {
    scanf("%d %d", &n, &M);
    backtrack(1, 0);
    return 0;
}