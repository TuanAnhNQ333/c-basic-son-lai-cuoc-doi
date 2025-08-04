#include<stdio.h>
#include<stdlib.h>
void split(double num, int *int_part, double *frac_part) {
    *int_part = (int)num;
    *frac_part = num - *int_part;
}
int main() {
    double num, fraction;
    int integer;

    printf("enter a real number:");
    scanf("%lf", &num);

    split(num, &integer, &fraction);
    printf("integer part : %d\n", integer);
    printf("fraction part : %f\n", fraction);

    return 0;
}