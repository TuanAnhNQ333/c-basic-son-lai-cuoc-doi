/*
Given a float number A, the integer part I is defined to be the largest integer that is less than or equal to A, and the decimal part D is defined to be A - I. Compute the integer and decimal parts of A.
Input
The float number A
Output
Write the integer and decimal parts of A (separated by a SPACE character) (the decimal part is written with 2 digits after the decimal point)

Example
Input 
2.57902
Output 
2 0.58

Input 
-4.3456
Output 
-5 0.65 
*/
#include<stdio.h>
int main() {
    double number;
    scanf("%lf", &number);
    if(number > 0) {
        int round1_number = (int)(number);
        double decimal1_number = number - round1_number;
        printf("%d %.2lf", round1_number, decimal1_number);
    } else if (number < 0) {
        int round2_number = (int)(number) - 1;
        double decimal2_number = number - round2_number;
        printf("%d %.2lf", round2_number, decimal2_number);
    }
    return 0;
}