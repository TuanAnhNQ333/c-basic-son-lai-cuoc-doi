#include<stdio.h>
int gcd(int a, int b) {
    if(a == b) {
        return a;
    } else if( a < b ) {
        return gcd(a, b-a);
    } else {
        return gcd(a-b, b);
    }
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = gcd(a, b);
    printf("%d", result);
    return 0;
}