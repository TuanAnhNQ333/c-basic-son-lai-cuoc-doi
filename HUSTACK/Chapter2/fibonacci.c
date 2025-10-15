/*
F[0] = 0, F[1] = 1.
F[n] = F[n-1] + F[n-2], for n >= 2

Compute F[n] for a given positive integer n
Input
Line 1 : contains a positive integer n (2 <= n <= 100000)

Output
Write the value (F[n] mod 1000000007)

Example
Input
4
Output
3
*/
#include<stdio.h>
#define max 1000000007
#define maxlen 100000
int array[maxlen] = {0};
long long fibonacci(int n) {
    if(array[n] != 0) {
        return array[n];
    }
    if(n <= 1) {
        return n;
    }
    array[n] = (fibonacci(n-1) + fibonacci(n-2)) % max;
    return array[n];
}
int main() {
    int n;
    
    scanf("%d", &n);
    long long result = fibonacci(n) ;
    printf("%lld", result);
    return 0;
    
}
