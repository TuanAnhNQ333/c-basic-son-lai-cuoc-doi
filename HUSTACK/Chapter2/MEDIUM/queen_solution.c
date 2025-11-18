/*
Chapter 2 - Count number of Queen solutions with some specified queens
Trung bình
Back Tracking
Given a chess board N x N on which there are K being placed in some cells. Compute the number of solutions to place other N - K queens in other cells such that among N queens on the board, no two queens attack each other.
A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.

Input
Line 1: contains a positive integer N (1 <= N <= 12)
Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A
Output
Write the number of solutions

Example
Input 
4
0 1 0 0
0 0 0 0
0 0 0 0
0 0 1 0
Output
1


Input 
5
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Output 
2
*/
#include <stdio.h>

#define MAXN 12

int N;
int board[MAXN][MAXN];
int result = 0;

// Kiểm tra có thể đặt quân hậu ở (row, col) hay không
int isSafe(int row, int col) {
    for (int i = 0; i < N; i++) {
        // Kiểm tra cùng cột
        if (i != row && board[i][col] == 1) return 0;
    }
    for (int j = 0; j < N; j++) {
        // Kiểm tra cùng hàng
        if (j != col && board[row][j] == 1) return 0;
    }
    // Kiểm tra đường chéo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                if (i + j == row + col) return 0; // đường chéo chính
                if (i - j == row - col) return 0; // đường chéo phụ
            }
        }
    }
    return 1;
}

// Đệ quy Backtracking
void solve(int row) {
    if (row == N) {
        result++;
        return;
    }

    // Nếu hàng này đã có quân hậu cố định, đi tiếp hàng tiếp theo
    int hasQueen = 0;
    for (int col = 0; col < N; col++) {
        if (board[row][col] == 1) {
            hasQueen = 1;
            break;
        }
    }
    if (hasQueen) {
        solve(row + 1);
        return;
    }

    // Thử đặt quân hậu vào các ô trống
    for (int col = 0; col < N; col++) {
        if (board[row][col] == 0 && isSafe(row, col)) {
            board[row][col] = 1;      // đặt quân hậu
            solve(row + 1);
            board[row][col] = 0;      // backtrack
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    solve(0);

    printf("%d\n", result);
    return 0;
}
