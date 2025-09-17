/*
Mô tả
Viết một hàm nhận đối số là hai mảng số nguyên, có cùng số phần tử. Hàm trả về:
1 nếu hai mảng có nội dung trùng nhau 
Hàm trả về -1 nếu 2 mảng có nội dung đối xứng (mảng này ngược với mảng kia, và hai mảng này không trùng nhau).
và 0 cho các trường hợp còn lại.
Kiểm tra hoạt động của hàm qua một chương trình.

int compare_arrays(int arr1[], int arr2[], int size)

Input:
N
Các số nguyên của mảng thứ nhất, giữa hai số nguyên ngăn cách nhau bằng dấu cách
Các số nguyên của mảng thứ hai, giữa hai số nguyên ngăn cách nhau bằng dấu cách

Output:
Số nguyên mô tả kết quả so sánh hai mảng, mang 1 trong 3 giá trị: 1 -1 0*/

#include <stdio.h>

int compare_arrays(int N, int arr1[], int arr2[]) {
    int result = 0;
    for (int i = 0; i < N; i++) {
        if(arr1[i] == arr2[i]) {
            result = 1;
        }
        else if(arr1[i] == arr2[N-i-1]) {
            result = -1; // đói xứng
        }
        else   {
            result = 0; // Mảng khác nhau
        }    
    }
    return result; // Mảng giống nhau

}
int main(void) {
    int N;
    scanf("%d", &N);

    int input1[N] , input2[N] ;
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &input1[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &input2[i]);
    }

   if (compare_arrays(N, input1, input2) == 1) {
       printf("1");
   } else if(compare_arrays(N, input1, input2) == -1){
       printf("-1");
   } else {
        printf("0");
   }

   return 0;
}