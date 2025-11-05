/*
 Thuật toán
• Chuyển n-1 đĩa từ cọc A sang cọc C, lấy B làm cọc trung
gian
• Chuyển 1 đĩa từ cọc A sang cọc B
• Chuyển n-1 đĩa từ cọc C sang cọc B, lấy A làm cọc trung
gian
• Số bước cần thực hiện là 2n -1*/
#include<stdio.h>
void control_plate(int n, int a, int b, int c) {
    if(n == 1) {
        printf("%d %d\n", a, b);
        return ;
    }
    control_plate(n - 1, a, c , b);
    control_plate(1, a, b, c);
    control_plate(n - 1, c, b, a);
}
int main() {
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    control_plate(n, a, b, c);
    return 0;
}      