/*
Given a chess board N x N on which there are N being placed in N different cells. 
Write a program that check if there are two queen, that attacks each other.

A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.
Input
Line 1: contains a positive integer T which is the number of test-cases (1 <= T <= 100)
T following block, each block is the input of a test-case with the format:
Line 1: contains a positive integer N (1 <= N <= 100)
Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A
Output
In each line t (t = 1, 2, ..., T), write 1 if in the test-case t, there are no two queen that attack each other, and write 0, otherwise 
Example
Input
2
4
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
4
0 1 0 0
0 0 0 0
1 0 0 1
0 0 1 0
Output
1
0
*/
#include<stdio.h>
#include<string.h>
int check_queen(int **matrix) {

}
int main() {
    int query;
    scanf("%d", &query);
    int n;
    int matrix[n][n];
    for(int m = 0; m < query; m ++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) {
            for(int j = 0;  j < n; j ++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        for(int j = 0; j < n; j ++) {
            int queen_solution = 0;
            
        }
    }
}
