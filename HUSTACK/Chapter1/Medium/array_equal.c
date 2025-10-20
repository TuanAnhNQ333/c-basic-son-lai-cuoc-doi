/*
Given two sequence a=a
1,…,an
 and b=b1,…,bm
. Check if these sequences are equal.
Input
Line 1: contains a positive integer T (1≤T≤10
2
) represents number of tests
Follow are T tests, each of which has the following format
Line 1: n and m (1≤n,m≤1000)
Line 2: a
1
,…,a
n
Line 3: b
1
,…,b
m


Output
Write to stdout T lines, each line t contains 1 if the sequences of the t
th
 test are equal, and write 0, otherwise.
Example
Input
3
3 3
1 2 3
1 2 3
4 2
1 2 3 4
1 2
3 3
2 4 1
2 3 1
Output
1
0
0*/
#include<stdio.h>
#include<string.h>
#define maxlen 10000
int main() {

    int T ; //test
    scanf("%d", &T);

    int check[T] ;
    
    for(int t = 0; t < T; t ++) {
        int n, m;

        scanf("%d %d", &n, &m);
        int a[maxlen];
        int b[maxlen];
        for(int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < m; i ++) {
            scanf("%d", &b[i]);
        }
        if(n != m) {
            check[t] = 0;
            continue;
        }
        check[t] = 1;
        for(int i = 0; i < n; i ++) {
            if(a[i] != b[i]) {
                check[t] = 0;
                break;
            }
        }
    }
    for(int i = 0; i < T; i ++) {
         printf("%d\n", check[i]);
    }
    
    return 0;

}