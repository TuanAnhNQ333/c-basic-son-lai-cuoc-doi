/*
Cho xâu S có N < 120000 ký tự chữ số. Hãy xóa đi K (K < N) ký tự để xâu còn lại biểu diễn một số bé nhất 
(số có thể bắt đầu bằng chữ số 0). 
Đầu vào có dòng 1 chứa xâu độ dài tối đa. Dòng 2 chứa K. Đầu ra là xâu sau khi xóa.
Ví dụ
Input:
869357495356872
9
Output:
335672
*/
#include <stdio.h>
#include <string.h>

int main() {
    char S[120005]; // +5 cho an toàn
    int K;
    
    // Đọc dữ liệu
    scanf("%s", S);
    scanf("%d", &K);
    
    int len = strlen(S);
    char stack[120005];
    int top = -1; // chỉ số của đỉnh stack
    
    for (int i = 0; i < len; i++) {
        char c = S[i];
        // Xóa các chữ số trên stack nếu còn K và chữ số trên stack > chữ số hiện tại
        while (top >= 0 && K > 0 && stack[top] > c) {
            top--;
            K--;
        }
        stack[++top] = c; // đẩy chữ số hiện tại vào stack
    }
    
    // Nếu vẫn còn K chưa xóa, xóa từ cuối stack
    top -= K;
    
    // In kết quả
    for (int i = 0; i <= top; i++) {
        putchar(stack[i]);
    }
    putchar('\n');
    
    return 0;
}
