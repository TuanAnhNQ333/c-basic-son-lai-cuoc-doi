/*
Given 3 integers a, b, c (c != 0). Write a program that find distinct integers solution s1, s2, . . ., sk) such that x
3
 + ax
2
 + bx + c can be rewritten under the form (x-s1) 
m1
(x-s2)
m2
. . . (x-sk)
mk   
in which m1, m2,  . . ., mk are call multipliers.

Input
Line 1 contains 3 integers a, b, c (-10000000 <= a, b, c <= 10000000)
Output
In case that no solution found, then write NO SOLUTION to stdout. Otherwise, write the solution under the format: 
s1 m1
s2 m2
s3 m3
. . .
in which s1, s2, s3, ... are solution sorted in an increasing order and m1, m2, m3, ... are respectively the multipliers of s1, s2, s3, ...

Example
Input
-1  -1  -2
Output
NO SOLUTION

Input 
-6 11 -6
Output 
1 1
2 1
3 1

Input 
8  5  -50
Output 
-5  2
2   1
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main() {
    int a, b, c, k;
    int m1, m2;
    scanf("%d %d %d", &a, &b, &c);
    if(a == 0 || b == 0 || c == 0) {
        printf("NO SOLUTION");
    }
    else {
        long long absC = llabs(c);
        for(long long i = 1; i <= absC; i ++) {
            if(absC % i == 0) {
                long long candidate[2] = {i, -i};
                for(int j = 0; j < 2; j ++) {
                    long long x = candidate[j];
                    long long value = x*x*x + a*x*x + b*x + c;
                    if(value == 0) {
                        k = x;
                    }
                }
            }
        }
        m1 = (-c - b * k) / (k * k);
        m2 = (-c) / k;
        int delta = (m1 * m1) - (4*m2);
        if(delta < 0) {
            printf("NO SOLUTION");
        } else if(delta == 0) {
            int x2 = (-m1)/2;
            if(x2 == k) {
                printf("%d 3", k);
            } else {
                printf("%d 2\n", x2);
                printf("%d 1", k);
            }
        } else {
            int solve1 = (-m1 - sqrt(delta)) / 2;
            int solve2 = (-m1 + sqrt(delta)) / 2;
            if(solve1 == k) {
                printf("%d 2\n", k);
                printf("%d 1", solve2);
            } else if(solve2 == k) {
                printf("%d 2\n", solve1);
                printf("%d 1", k);
            } else {
                if(k < solve1) {
                    printf("%d 1\n", k);
                    printf("%d 1\n", solve1);
                    printf("%d 1\n", solve2);
                } else if( k > solve2) {
                    printf("%d 1\n", solve1);
                    printf("%d 1\n", solve2);
                    printf("%d 1", k);
                } else {
                    printf("%d 1\n", solve1);
                    printf("%d 1\n", k);
                    printf("%d 1", solve2);
                }
            }
        }
    }
    
    return 0;
}