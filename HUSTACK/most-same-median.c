/*
Mô tả
Nhập một mảng số thực có 8 phần tử.
Xác định chỉ số và giá trị của phần tử mảng có giá trị gần nhất với giá trị trung bình của tất cả các phần tử mảng.
Lưu ý: Phải sử dụng HẰNG CONSTANT = 8 trong khai báo kích thước mảng.
Input: 8 số thực, mỗi số trên một dòng
Output: chỉ số và giá trị của phần tử mảng (với độ chính xác 2 chữ số sau dấu phẩy), hai giá trị này ngăn cách bởi dấu cách

tìm median(double) -> tạo mảng lưu hiệu của array[i]-median -> tìm giá trị hiệu nhỏ nhất -> số gần nhất với median
*/
#include<stdio.h>
#include<math.h>
#define CONSTANT 8
double mean(double *array) {
    double sum = 0;
    for(int i = 0; i < CONSTANT; i ++) {
        sum += array[i];
    }
    return sum/CONSTANT;
}
int main() {
    double array[CONSTANT] = {0};
    for(int i = 0; i < CONSTANT; i ++) {
        scanf("%lf", &array[i]);
    }

    double med = mean(array);
    int index = 0;
    double mindiff = fabs(array[0] - med);
    for(int i = 1; i < CONSTANT; i ++) {
        double diff = fabs(array[i] - med);
        if(diff < mindiff) {
            mindiff = diff;
            index = i;
        }
    }
    printf("Trung binh: %.2lf\n", med);
    printf("%d %.2lf", index, array[index]);
    return 0;
}