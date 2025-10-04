/*
Given a matrix T having n rows and m columns, each element is 0 or 1. A column is called black column if each element on this column is 1. Write a program to compute the number Q of black columns

Input
Line 1: contains two positive integers n and m (1 <= n,m <= 1000)
Line i+1 (i = 1,...,n): contains the i
th
 row of the matrix T
Output
Write the value of Q

Example
Input
4 4
1 0 1 0
1 1 1 0
1 0 1 1
1 1 1 1

Ouput 
2 */
#include<stdio.h>
int main() {
    int n, m; // n : row, m : column
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int q = 0;
    for(int j = 0; j < m; j ++) {
        int is_black = 1;
        for(int i = 0; i < n; i ++) {
            if(matrix[i][j] != 1) {
                is_black = 0; 
                break;
            }
        } if(is_black) {
            q ++;
        }
    }
    printf("%d", q);
    return 0;
}