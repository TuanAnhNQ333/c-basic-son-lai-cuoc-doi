/*
Cho số nguyên dương n . Hãy viết chương trình liệt kê tất cả các hoán vị của 1, 2, . . ., ntheo thứ tự
từ điển
• Dữ liệu
• Kết quả
• Dòng duy nhất chứa số nguyên dương n (1 <= n<= 10)
• Ghi ra trên mỗi dòng 1 hoán vị (sau mỗi phần tử của hoán vị là 1 ký tự SPACE)
*/
#include<stdio.h>
#define N 20
int n;
int x[N];
int mark[N];

int check_status(int v, int k) {
    return mark[v] == 0;
}
void print_solution(void) {
    for(int i = 1; i <= n; i ++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}
void try(int k) {
    for(int v = 1; v <= n; v ++) {
        if(check_status(v, k)) {
            x[k] = v;
            mark[v] = 1;
            if(k == n) {
                print_solution();
            }
            else {
                try(k + 1);
            }
            mark[v] = 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int v = 1; v <= n; v ++) {
        mark[v] = 0;
    }
    try(1);
    return 0;
}


