/*
BÀI TOÁN THÁP HÀ NỘI (P.02.04.03)

• Cho n đĩa có bán kính khác nhau và 3 cọc A, B, C. Ban đầu n đĩa nằm ở cọc A theo thứ tự đĩa nhỏ ở
  trên và đĩa lớn ở dưới. Hãy tìm cách chuyển n đĩa từ cọc A sang cọc B (dùng cọc C làm trung gian)
  theo nguyên tắc:

• Mỗi bước chỉ được chuyển 1 đĩa trên cùng từ 1 cọc sang 1 cọc khác (đặt trên cùng)
• Không được phép để xảy ra trường hợp đĩa lớn nằm bên trên đĩa bé ở 1 cọc nào đó

• Dữ liệu:
  • Dòng duy nhất chứa 4 số nguyên dương n, A, B, C (1 <= n <= 20, 1 <= A, B, C <= 100)

• Kết quả:
  • Dòng 1 ghi số nguyên dương m (số bước thực hiện)
  • Dòng i + 1 (i = 1, 2, …, m) chứa 2 số nguyên dương X và Y: tại bước i, ta chuyển 1 đĩa từ cọc X
    sang cọc Y

stdin       stdout
2 11 22 33  3
            11 33
            11 22
            33 22
*/

#include <stdio.h>

int moves = 0;

void hanoi(int n, int source, int target, int auxiliary) {
    if (n == 1) {
        // Base case: move single disk from source to target
        printf("%d %d\n", source, target);
        moves++;
        return;
    }
    
    // Move n-1 disks from source to auxiliary using target as auxiliary
    hanoi(n-1, source, auxiliary, target);
    // Move the largest disk from source to target
    printf("%d %d\n", source, target);
    moves++;
    
    // Move n-1 disks from auxiliary to target using source as auxiliary
    hanoi(n-1, auxiliary, target, source);

}

int main() {
    int n, A, B, C;
    
    // Input number of disks and pole numbers
    scanf("%d %d %d %d", &n, &A, &B, &C);
     
    // First print total number of moves (2^n - 1)
    printf("%d\n", (1 << n) - 1);
    
    // Solve Tower of Hanoi recursively
    hanoi(n, A, B, C);
    
    return 0;
}                   