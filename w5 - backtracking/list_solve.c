/*
• Cho số nguyên dương nvà M , hãy viết chương trình liệt kê tất cả các bộ X 1, X 2, …, X n (theo thứ tự
từ điển) sao cho
X 1 + X 2 + . . . + X n = M
• Dữ liệu
• Kết quả
• Dòng 1: chứa số nguyên dương nvà M(2 <= n<= 10, 1 <= M<= 20)
• Ghi ra trên mỗi dòng một bộ giá trị của X 1, X 2, …, X n (sau mỗi phần tử là 1 ký tự SPACE)
*/
#include<stdio.h>
#define N 20
int n;
int m;
int a[N];

void try(int i, int sum) {
    if(i == n) {
        if(sum == m) {
            for(int j = 0; j < n; j ++) {
                printf("%d ", a[j]);
            }
            printf("\n");
        }
        return ;
    }
    for(int value = 1; value <= m - sum; value ++) {
        a[i] = value;
        try(i + 1, sum + value);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    try(0, 0);
    return 0;
}