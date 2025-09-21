/*
BÀI TOÁN DÃY SỐ FIBONACCI (P.02.04.04)

• Mô tả:
  Cho số nguyên dương n, hãy tính số Fibonacci thứ n.
  Dãy Fibonacci được định nghĩa như sau:
    F(n) = n,          khi n = 0, 1
    F(n) = F(n-1) + F(n-2), khi n ≥ 2

• Dữ liệu:
  - Dòng 1: chứa số nguyên dương n (2 ≤ n ≤ 100000)

• Kết quả:
  - Ghi giá trị F(n) mod (10^9 + 7)

• Ví dụ:
  stdin   stdout
  10      55
*/
#include<stdio.h>
#define max_len 1000000000000
int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    
    return (fibonacci(n-1) + fibonacci(n-2)) % max_len;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}