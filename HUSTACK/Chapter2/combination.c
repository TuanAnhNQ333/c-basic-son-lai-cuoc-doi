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
#define max 1000000007
#define maxlen 1000
long long array[maxlen][maxlen] = {0};
long long combination(int k, int n) {
    if(k > n) return 0;
    if(k == 0 || k == n) {
        array[k][n] = 1;
    } 
    else {
        if(array[k][n] == 0) {
            array[k][n] = (combination(k - 1, n - 1) + combination(k, n - 1)) % max;
        }
    }
    return array[k][n];
}
int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%lld", combination(k, n));
    return 0;
}