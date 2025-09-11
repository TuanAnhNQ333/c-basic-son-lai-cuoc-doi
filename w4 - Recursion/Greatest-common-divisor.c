/*
BÀI TOÁN ƯỚC SỐ CHUNG LỚN NHẤT (P.02.04.01)
• Cho hai số nguyên dương a và b. Hãy viết chương trình tìm ước số chung lớn nhất của a và b.
• Dữ liệu
• Kết quả
• Dòng 1: ghi 2 số nguyên dương a và b (1 <= a, b <= 100000)
• Ghi ra ước số chung lớn nhất của a và b
stdin
stdout
16 24
8
*/

#include <stdio.h>

// Recursive function to find GCD using Euclidean algorithm
int gcd(int a, int b) {
    // Base case: if b is 0, a is the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: GCD(a,b) = GCD(b, a mod b)
    return gcd(b, a % b);
}

int main() {
    int a, b;
    
    // Input two numbers
    scanf("%d %d", &a, &b);
    
    // Calculate and print GCD using recursion
    printf("%d\n", gcd(a, b));
    
    return 0;
}