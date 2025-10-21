/*Given two matrices Anxk  and Bkxm
. Each element of the two matrices are integers from 1 to 50. Compute the product matrix C = A x B.
 
Input
Line 1 contains two positive integers n and k (1 <= n, k <= 100)
Line i+1 (i = 1,2, ..., n): contains the i
th
 row of A (elements are separated by a SPACE character)
Line n+2: contains two positive integers k and m (1 <= k,m <= 100)
Line i+n+2 (i= 1, 2, ..., k): contains the 
ith
 row of B (elements are separated by a SPACE character)

Output
Line i (i = 1,...,n) contains the i
th
 row of the resulting matrix (elements are separated by a SPACE character)

Example
Input
2 3
1 2 3
4 5 6
3 4
1 1 1 1
2 2 2 2
3 3 3 3

Output
14 14 14 14
32 32 32 32
*/
#include<stdio.h>

#define maxlen 100
int main() {
    int n, k, m, k2;
    int matrix1[maxlen][maxlen];
    int matrix2[maxlen][maxlen];
    int result[maxlen][maxlen] = {0};
    // input 1st matrix
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < k; j ++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    // input 2nd matrix
    scanf("%d %d", &k2, &m);
    if(k2 != k) { return 1;}
    for(int i = 0; i < k; i ++) {
        for(int j = 0; j < m; j ++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    // solve multi
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            for(int t = 0; t < k; t ++) {
                result[i][j] += matrix1[i][t] * matrix2[t][j];
            }
        }
    }
    // print result
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            printf("%d", result[i][j]);
            if(j < m - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}