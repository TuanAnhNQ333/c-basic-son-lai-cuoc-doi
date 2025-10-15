#include<stdio.h>
void convert_to_binary(int N) {
    if(N == 0) {
        return ;
    }
    convert_to_binary(N/2);
    int b = N % 2;
    printf("%d", b);
}
int main() {
    int N; 
    scanf("%d", &N);
    convert_to_binary(N);
    return 0;
}