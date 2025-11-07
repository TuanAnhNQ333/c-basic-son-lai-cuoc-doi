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
#include <stdio.h>
#include <stdlib.h> // để dùng abs()

int main() {
    int T;
    scanf("%d", &T); 
    
    while (T--) {          
        int n;
        scanf("%d", &n);
        int A[105][105];
        int queens[105][2];
        int qCount = 0;
        
        // Nhập ma trận và lưu vị trí các quân hậu
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
                if (A[i][j] == 1) {
                    queens[qCount][0] = i;
                    queens[qCount][1] = j;
                    qCount++;
                }
            }
        }

        int ok = 1;
        // Kiểm tra các cặp hậu xem có ăn nhau không
        for (int i = 0; i < qCount && ok; i++) {
            for (int j = i + 1; j < qCount; j++) {
                int r1 = queens[i][0], c1 = queens[i][1];
                int r2 = queens[j][0], c2 = queens[j][1];
                if (r1 == r2 || c1 == c2 || abs(r1 - r2) == abs(c1 - c2)) {
                    ok = 0;
                    break;
                }
            }
        }

        printf("%d\n", ok);
    }
    return 0;
}

