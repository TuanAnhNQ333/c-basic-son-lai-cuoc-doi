/*
PAIR SUM
• Description:
  Given a sequence of positive integer numbers a1...an and a query integer x,
  calculate the number of pairs (ai, aj) where ai + aj <= x.
• Input:
  - Line 1: Contains n (number of elements)
  - Line 2: Contains n positive integers a1...an
  - Line 3: Contains q (number of queries)
  - Next q lines: Each contains a query integer x
• Output:
  - q lines, each containing the number of pairs satisfying the corresponding query
• Example:
  Input:
    5
    5 10 2 7 9
    2
    15
    13
  Output:
    7
    5
*/
#include<stdio.h>
#include<stdlib.h>

int pair_sum(int N, int array[], int x) {
    int count = 0;
    for(int i = 0; i < N; i ++) {
        for(int j = i + 1; j < N; j ++) {
            if(array[i] + array[j] <= x) {
                count ++;
            }
        }
    }
    return count;

}
int main() {
    
    int N;
    scanf("%d", &N);

    int array[N];
    for(int i = 0; i < N; i ++ ) {
        scanf("%d", &array[i]);
    }
    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i ++) {
        int query;
        scanf("%d", &query);
        int result = pair_sum(N, array, query);
        printf("%d\n", result);
    }

    return 0;
}