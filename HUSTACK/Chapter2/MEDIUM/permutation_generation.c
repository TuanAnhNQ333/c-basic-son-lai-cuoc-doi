/*
Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
Example
Input 
3
Output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/
#include <stdio.h>
#define N 20

int n;
int x[N];
int mark[N];

void print_solution(void) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Generate all permutations of 1..n in lexicographic order (backtracking)
void generate(int k) {
    for (int v = 1; v <= n; v++) {
        if (!mark[v]) {
            x[k] = v;
            mark[v] = 1;
            if (k == n) {
                print_solution();
            } else {
                generate(k + 1);
            }
            mark[v] = 0; // backtrack
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) mark[i] = 0;
    generate(1);
    return 0;
}