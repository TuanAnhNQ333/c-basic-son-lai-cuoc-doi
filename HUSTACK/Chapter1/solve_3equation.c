/*Mô tả
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
*/ // chưa tìm công thức giải 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SOLUTIONS 100

// Function to evaluate polynomial at x
double evaluate(int a, int b, int c, double x) {
    return pow(x, 3) + a*pow(x, 2) + b*x + c;
}

// Function to check if x is an integer solution
int isIntegerSolution(int a, int b, int c, int x) {
    return (pow(x, 3) + a*pow(x, 2) + b*x + c == 0);
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    int solutions[MAX_SOLUTIONS];
    int multiplicities[MAX_SOLUTIONS];
    int solutionCount = 0;
    
    // Try integer values in reasonable range based on coefficients
    int range = (int)ceil(pow(abs(c), 1.0/3) + 2);
    
    for(int x = -range; x <= range; x++) {
        if(isIntegerSolution(a, b, c, x)) {
            // Count multiplicity
            int multiplicity = 0;
            double derivative = evaluate(a, b, c, x);
            while(fabs(derivative) < 1e-10) {
                multiplicity++;
                derivative = evaluate(a, b, c, x + 1e-10) - evaluate(a, b, c, x);
            }
            multiplicity = multiplicity ? multiplicity : 1;
            
            solutions[solutionCount] = x;
            multiplicities[solutionCount] = multiplicity;
            solutionCount++;
        }
    }
    
    if(solutionCount == 0) {
        printf("NO SOLUTION\n");
    } else {
        // Sort solutions
        for(int i = 0; i < solutionCount-1; i++) {
            for(int j = 0; j < solutionCount-i-1; j++) {
                if(solutions[j] > solutions[j+1]) {
                    // Swap solutions
                    int temp = solutions[j];
                    solutions[j] = solutions[j+1];
                    solutions[j+1] = temp;
                    // Swap multiplicities
                    temp = multiplicities[j];
                    multiplicities[j] = multiplicities[j+1];
                    multiplicities[j+1] = temp;
                }
            }
        }
        
        // Print solutions
        for(int i = 0; i < solutionCount; i++) {
            printf("%d %d\n", solutions[i], multiplicities[i]);
        }
    }
    
    return 0;
}