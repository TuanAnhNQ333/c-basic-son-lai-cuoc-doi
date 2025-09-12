/*
BÀI TOÁN ĐỔI SỐ NGUYÊN SANG DÃY BÍT NHỊ PHÂN (P.02.04.02)
• Cho số nguyên dương N, hãy viết chương trình đổi N sang chuỗi bít nhị phân (bỏ qua các bit 0 ngoài
cùng bên trái)
• Dữ liệu
• Kết quả
• Dòng duy nhất chứa số nguyên dương N (1 <= N <= 2x107)
• Dòng duy nhất ghi chuỗi bit kết quả
stdin
stdout
20
10100*/

#include <stdio.h>

void decimalToBinary(int n) {
    // Base case: if n is 0, return
    if (n == 0) {
        return;
    }
    
    // Recursive case: first convert n/2, then print remainder
    decimalToBinary(n / 2);
    printf("%d", n % 2);
}

int main() {
    int N;
    
    // Input number
    scanf("%d", &N);
    
    // Handle special case for input = 0
    if (N == 0) {
        printf("0\n");
        return 0;
    }
    
    // Convert and print binary using recursion
    decimalToBinary(N);
    printf("\n");
    
    return 0;
}