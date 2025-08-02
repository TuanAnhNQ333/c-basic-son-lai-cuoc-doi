#include<stdio.h>
int i = 0;
void HanoiTower (int n, char xuatphat, char dich, char trunggian) {
    if(n == 1) {
        printf("Dich chuyen dia tu coc %c den coc %c\n", xuatphat, dich);
        i ++;
        return;
    } else {
        HanoiTower (n - 1, xuatphat, trunggian, dich);
        HanoiTower (1, xuatphat, dich, trunggian);
        HanoiTower (n - 1, trunggian, dich, xuatphat);
    }
}
int main() {
    int n;
    printf("Nhap so dia n = ");
    scanf("%d", &n);
    HanoiTower(n, 'a', 'c', 'b');
    printf("Tong so lan dich chuyen la : %d", i);
    return 0;
}