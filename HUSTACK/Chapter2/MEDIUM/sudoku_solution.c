/*
Viết chương trình để tính số lượng giải pháp sudoku (điền các phần tử bằng 0 vào một bảng sudoku một phần cho trước)
Điền các số từ 1, 2, 3, .., 9 đến bảng 9 x 9 sao cho:
Số của mỗi hàng là khác nhau
Số của mỗi cột là khác nhau
Các số trên mỗi ô vuông phụ 3 x 3 là khác nhau
Đầu vào
Mỗi dòng i ( i = 1, 2, ..., 9) chứa các phần tử của i
th
hàng của bảng Sudoku: các phần tử là các số từ 0 đến 9 (giá trị 0 có nghĩa là ô trống của bảng)
Đầu ra
Viết số giải pháp tìm được

Ví dụ
Đầu vào
0 0 3 4 0 0 0 8 9
0 0 6 7 8 9 0 2 3
0 8 0 0 2 3 4 5 6
0 0 4 0 6 5 0 9 7
0 6 0 0 9 0 0 1 4
0 0 7 2 0 4 3 6 5
0 3 0 6 0 2 0 7 8
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
Đầu ra
64
*/

#include <stdio.h>
#define N 9

int sudoku[N][N];
int solution = 0;

// Kiểm tra tính hợp lệ khi điền "number" vào vị trí (row, column)
int is_valid(int row, int column, int number) {
    for(int i = 0; i < N; i++) {
        if(sudoku[row][i] == number) return 0;
        if(sudoku[i][column] == number) return 0;
    }
    int box_row = (row / 3) * 3;
    int box_col = (column / 3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku[box_row + i][box_col + j] == number) return 0;
        }
    }
    return 1;
}

// Đệ quy thử từng cách điền sudoku
void solve_sudoku(int row, int column) {
    if(row == N) {
        solution++;
        return;
    }
    if(column == N) {
        solve_sudoku(row + 1, 0);
        return;
    }
    if(sudoku[row][column] != 0) {
        solve_sudoku(row, column + 1);
        return;
    }
    for(int number = 1; number <= 9; number++) {
        if(is_valid(row, column, number)) {
            sudoku[row][column] = number;
            solve_sudoku(row, column + 1);
            sudoku[row][column] = 0;
        }       
    }
}

int main() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    solve_sudoku(0, 0);
    printf("%d", solution);
    return 0;
}