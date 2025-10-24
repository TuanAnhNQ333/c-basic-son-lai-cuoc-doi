/*
Given a string representing a math expression including operator + and * and operands which are positive integers. Compute the value Q of this expression.
Input
Line 1: contains the string representing the expression (number of operators is upto 10000)
Output
Write the value Q modulo 10
9
+7 if the expression is mathematically correct in term of the syntax, and write NOT_CORRECT, otherwise
Example
Input
5+7*3*10*10
Output
2105
Input
5*+ 7*3*10*10
Output
NOT_CORRECT
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MOD 1000000007
#define MAXL 100005

int main() {
    char buf[MAXL];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    // 1) xóa khoảng trắng
    char s[MAXL];
    int L = 0;
    for (int i = 0; buf[i] != '\0'; i++) {
        if (!isspace((unsigned char)buf[i])) s[L++] = buf[i];
    }
    s[L] = '\0';
    if (L == 0) { printf("NOT_CORRECT"); return 0; }

    // 2) parse numbers và operators, kiểm tra cú pháp
    long long nums[MAXL];
    char ops[MAXL];
    int numCount = 0, opCount = 0;
    int i = 0;
    while (i < L) {
        // phải bắt đầu bằng chữ số
        if (!isdigit((unsigned char)s[i])) { printf("NOT_CORRECT"); return 0; }

        long long val = 0;
        // đọc số (có thể nhiều chữ số)
        while (i < L && isdigit((unsigned char)s[i])) {
            val = val * 10 + (s[i] - '0');
            i++;
            // không cần kiểm tra overflow do dùng modulo sau khi tính
        }
        nums[numCount++] = val % MOD;

        // nếu hết chuỗi thì dừng
        if (i == L) break;

        // phải là operator + hoặc *
        if (s[i] != '+' && s[i] != '*') { printf("NOT_CORRECT"); return 0; }
        ops[opCount++] = s[i];
        i++;
        // sau operator phải có chữ số (kiểm tra ở vòng lặp tiếp theo)
        if (i >= L) { printf("NOT_CORRECT"); return 0; }
    }

    // phải có số = operators + 1
    if (numCount != opCount + 1) { printf("NOT_CORRECT"); return 0; }

    // 3) evaluate: các group * trước, + sau
    long long total = 0;
    long long term = nums[0]; // term = product các số trong nhóm hiện tại
    for (int k = 0; k < opCount; k++) {
        if (ops[k] == '*') {
            term = (term * nums[k+1]) % MOD;
        } else { // ops[k] == '+'
            total = (total + term) % MOD;
            term = nums[k+1];
        }
    }
    total = (total + term) % MOD;

    printf("%lld", total);
    return 0;
}
