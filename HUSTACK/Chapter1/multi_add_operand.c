/*
Given a string representing a math expression including operator + and * and operands which are 
positive integers. Compute the value Q of this expression.

Input:
- Line 1: contains the string representing the expression (number of operators is up to 10000)

Output:
- Write the value Q modulo 10^9+7 if the expression is mathematically correct in terms of syntax
- Write NOT_CORRECT otherwise
Example 1:
Input:
5+7*3*10*10
Output:
2105

Example 2:   
Input:
5*+ 7*3*10*10
Output:
NOT_CORRECT
*/ // hướng giải : thay thế xâu : 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MOD 1000000007

int main() {
    char s[100005];
    if (!fgets(s, sizeof(s), stdin)) return 0;

    // Xóa khoảng trắng
    int len = strlen(s);
    char expr[100005];
    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(s[i])) expr[idx++] = s[i];
    }
    expr[idx] = '\0';

    // Kiểm tra chuỗi rỗng
    if (idx == 0) {
        printf("NOT_CORRECT");
        return 0;
    }

    long long total = 0;    // Tổng cuối cùng
    long long current = 1;  // Nhóm nhân hiện tại
    long long num = 0;
    char lastOp = '+';      // Toán tử trước đó
    int expectNumber = 1;   // True nếu đang cần số

    for (int i = 0; i < idx; i++) {
        char c = expr[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            expectNumber = 0;
        } else if (c == '+' || c == '*') {
            // Kiểm tra cú pháp
            if (expectNumber) {
                printf("NOT_CORRECT");
                return 0;
            }

            if (lastOp == '+') total = (total + current) % MOD, current = num;
            else if (lastOp == '*') current = (current * num) % MOD;

            lastOp = c;
            num = 0;
            expectNumber = 1;
        } else {
            // Ký tự lạ
            printf("NOT_CORRECT");
            return 0;
        }
    }

    // Kiểm tra nếu kết thúc bằng toán tử
    if (expectNumber) {
        printf("NOT_CORRECT");
        return 0;
    }

    // Xử lý phần cuối
    if (lastOp == '+') total = (total + current) % MOD, current = num;
    else if (lastOp == '*') current = (current * num) % MOD;

    long long result = (total + current) % MOD;
    printf("%lld", result);
    return 0;
}
