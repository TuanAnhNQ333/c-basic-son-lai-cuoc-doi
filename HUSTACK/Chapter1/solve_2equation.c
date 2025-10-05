/*
Mô tả
Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
Input
Line 1 contains 3 integers a, b, c 
Output
Write NO SOLUTION if the given equation has no solution 
Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 

Example
Input 
1 1 8
Output 
NO SOLUTION 


Input 
1 -2 1
Output
1.00

Input 
1 -7 10
Output 
2.00 5.00
*/
#include<stdio.h>
#include<math.h>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int delta = b*b - 4*a*c;
    double result1 = 0;
    double result2 = 0;
    if(delta < 0) {
        printf("NO SOLUTION");
    } else if(delta == 0) {
        result1 = (-b) / 2;
        printf("%.2lf", result1);
    } else {
        result1 = (-b - sqrt(delta)) / (2 * a);
        result2 = (-b + sqrt(delta)) / (2 * a);
        printf("%.2lf %.2lf", result1, result2);
    }
    return 0;
}