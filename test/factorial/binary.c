#include<stdio.h>
int n;
int x[100];
void solution() {
    for(int k = 1; k <= n; k ++) {
        printf("%D ", x[k]);
    }
    printf("\n");
}
int check(int v, int k) {
    for(int i = 1; i <= k - 1; i ++) {
        if(x[i] == v) {
            return 0;
        }
    }
    return 1;
}
void Try(int k) {
    for(int v = 1; v <= n; v ++) {
        if(check(v, k)) {
            x[k] = v;
            if(k == n) {
                solution();
            }
            else {
                Try(k + 1);
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    Try(1);
}