/*Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
find-max: return the maximum element of the given sequence
find-min: return the minimum element of the given sequence 
sum: return the sum of the elements of the given sequence 
find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

Input
The first block contains the information about the given sequence with the following format:
Line 1: contains a positive integer n (1 <= n <= 10000)
Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
The first block is terminated by a character *
The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

Output
Write the result of each query in a corresponding line
 
Example
Input
5
1 4 3 2 5
*
find-max
find-min
find-max-segment 1 3
find-max-segment 2 5
sum
***

Output
5
1
4
5
15
*/
#include<stdio.h>
#include<string.h>

int max(int *array, int n) {
    int k = array[0];
    for(int i = 0; i < n; i ++) {
        if(k < array[i]) {
            k = array[i];
        }
    }
    return k;
}
int min(int *array, int n) {
    int k = array[0];
    for(int i = 0; i < n; i ++) {
        if(k > array[i]) {
            k = array[i];
        }
    }
    return k;
}
int sum(int *array, int n) {
    int result = 0;
    for(int i = 0; i < n; i ++) {
        result += array[i];
    }
    return result;
}
int max_segment(int *array, int i, int j) {
    int max = array[i];
    for(int t = i; t <= j; t ++) {
        if(max < array[t]) {
            max = array[t];
        }
    }
    return max;
}
int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i ++) {
        scanf("%d", &array[i]);
    }
    char query[100];
    scanf("%s", query);
    while(1) {
        if(scanf("%s", query) != 1) {
            break;
        }
        if(strcmp(query, "***") == 0) {
            break ;
        }
            if(strcmp(query, "find-max") == 0) {
                printf("%d\n", max(array, n));
            }
            else if(strcmp(query, "find-min") == 0) {
                printf("%d\n", min(array, n));
            }
            else if(strcmp(query, "sum") == 0) {
                printf("%d\n", sum(array, n));
            } else if(strcmp(query, "find-max-segment") == 0) {
                int i, j;
                scanf("%d %d", &i, &j);
                printf("%d\n", max_segment(array, i-1, j-1));
            
        }
    }  
    return 0;
}