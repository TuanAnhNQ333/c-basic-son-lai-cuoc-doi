/*
Cho số nguyên không âm k và n, hãy tính hằng số tổ hợp C(k, n)

• Dữ liệu
  • Dòng duy nhất chứa 2 số nguyên k và n (0 <= k, n <= 999)

• Kết quả
  • Ghi ra giá trị C(k,n) mod 109+7

C(k, n) = {
    1,                          khi k = 0 hoặc k = n
    C(k,n-1) + C(k-1,n-1),     ngược lại
}

stdin
3 5

stdout  
10
*/
#include<stdio.h>
int combination(int k, int n) {
    int result;
    if(k == 0 || k == n) {
        result = 1;
    } else {
        result = combination(k, n - 1) + combination(k - 1, n - 1);
    }
    return result;
}
int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d", combination(k, n));
    return 0;
}