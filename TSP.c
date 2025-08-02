#include<stdio.h>
#include<limits.h>

#define MAXN 20
#define INF INT_MAX 
int n;
int distances[MAXN][MAXN];
int dist[MAXN][MAXN];
int dp[1 << MAXN][MAXN]; // mang nho cho quy hoach dong
// ham TSP
/**
 * duyet qua tat ca thanh pho, kiem tra thanh pho chua tham
 * tinh toan chi phi tu thanh pho hien tai den tp chua tham
 * cap nhat chi phi toi thieu neu thay lo trinh tot hon
 */
int tsp (int mask, int pos) {
    if(mask == (1 << n) - 1) // tat ca cac thanh pho deu da tham
        return distances[pos][0]; // dieu kien dung : neu tat ca da tham -> quay lai tp ban dau
    if(dp[mask][pos] != -1) 
        return dp[mask][pos];
    int min_cost = INT_MAX;
    for(int city = 0; city < n; city ++) { // kiem tra tp co the di tiep tu tp hien tai (pos)
        if(!(mask & (1 << city))) {// thanh pho chua tham
            int new_cost = distances[pos][city] + tsp(mask | (1 << city), city);
            if(new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }
    return dp[mask][pos] = min_cost;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            scanf("%d", &distances[i][j]);
        }
    }
    // khoi tap dp
    for(int i = 0; i < (1 << n); i ++) {
        for(int j = 0; j < n; j ++) {
            dp[i][j] = -1;
        }
    }
    // find optimize result
    printf("%d\n", tsp(1, 0));
    return 0;
}
/**
 * Vấn đề: TSP
Sự miêu tả
Có n thành phố 1, 2, ..., n. Khoảng cách di chuyển từ thành phố i đến thành phố j là c(i,j), với i,j = 1, 2, ..., n. Một người khởi hành từ thành phố 1, ghé thăm mỗi thành phố 2, 3, ..., n đúng một lần và quay trở lại thành phố 1. Tìm lộ trình của người đó sao cho tổng khoảng cách di chuyển là nhỏ nhất.
Đầu vào
Dòng 1: số nguyên dương n (1 <= n <= 20)
Linr i+1 (i = 1, . . ., n): chứa i
th
hàng của ma trận khoảng cách x (các phần tử được phân tách bằng ký tự SPACE)
Đầu ra
Viết tổng quãng đường di chuyển của lộ trình tối ưu đã tìm được.
Ví dụ
Đầu vào
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Đầu ra
7
 */