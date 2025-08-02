#include <stdio.h>
#include<math.h>

void print_binary(int num, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int power_of_two = 1;
        for(int j = 0; j < i; j ++) {
            power_of_two *= 2;
        }
        int bit = (num / power_of_two) % 2; // lay bit thu i
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n); // Đọc giá trị n
    
    int total = pow(2, n); // 2^n dãy nhị phân
    
    for (int i = 0; i < total; i++) {
        print_binary(i, n); // In dãy nhị phân tương ứng với số i
    }
    
    return 0;
}