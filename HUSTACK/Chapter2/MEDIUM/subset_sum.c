/*
Given a sequence of n integers a1, a2, ..., an, and a positive integer b. Compute the number Q of way to select some elements from the given sequence such that the sum of selected elements is equal to b.
Input
Line 1: contains 2 integers n and b (1 <= n <= 50, 1 <= b <= 100)
Line 2: contains n positive integer a1, a2, ..., an (1 <= ai <= 100)
Output
Write the value Q

Example
Input 
5 6
1 2 3 4 5
Output
3
*/
#include<stdio.h>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    int a[51];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // dp[s] = number of ways to select elements with sum s
    int dp[101] = {0};
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int s = b; s >= a[i]; s--) {
            dp[s] += dp[s - a[i]];
        }
    }

    printf("%d", dp[b]);
    return 0;
}