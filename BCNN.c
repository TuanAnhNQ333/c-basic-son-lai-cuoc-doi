
#include<stdio.h>
#include<stdlib.h>
int gcd( int a, int b) {
    while(b != 0) {
         int temp = b; 
        b = a % b;
        a = temp;
    }
    return a;
}
// ham tinh lcm cua 2 so
long long  lcm(long long  a, long long  b, long long mod) {
    return (a / gcd(a, b) % mod) * (b % mod) % mod;
}
// ham tinh lcm cua day 1 -> n
long long lcm_of_array(long long arr[],int n) {
    const long long MOD = 1000000000;
    long long result =  arr[0] % MOD;
    for(int i = 1; i < n; i ++) {
        result = lcm(result, arr[i], MOD) ;
    }
    return result;
}
int main() {
    int n;
    scanf("%d", &n);
    if(n <= 0) {
        return 1;
    }
    long long *arr = (long long *)malloc(n * sizeof(long long));
    if(!arr) {
        return 1;
    }
    for(int i = 0; i < n; i ++){
        scanf("%lld", &arr[i]);
    }

    printf("%lld\n", lcm_of_array(arr,n));
    free(arr);
    return 0;

}
/**
 * Bài toán: Bội chung nhỏ nhất của n số
Sự miêu tả
Cho n số nguyên dương a[1], a[2], . . ., a[n]. Tính số nguyên dương nhỏ nhất N sao cho N chia hết cho a[1], a[2], . . ., a[n].

Đầu vào
Dòng 1: chứa số nguyên dương n (1 <= n <= 100000)
Dòng 2: chứa a[1], a[2], . . ., a[n] (1 <= a[i] <= 1000)

Đầu ra
Viết giá trị M mod 1000000000

Ví dụ
Đầu vào
3
6 14 20

Đầu ra
420
 */