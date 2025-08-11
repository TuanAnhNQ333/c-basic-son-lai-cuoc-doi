/*
Cải tiến bài tập tuần trước về chủ đề danh sách sinh viên – bảng điểm như sau:
• Thay vì mảng thông thường, chương trình cấp phát động đúng số bộ nhớ cần thiết để lưu
trữ dữ liệu đọc từ file danh sách lớp.
• Bổ sung tính năng nhập thêm: chương trình hỏi số lượng sinh viên cần nhập bổ sung, sau
đó tái cấp phát bộ nhớ động để có đủ bộ nhớ cho dữ liệu mới, sử dụng hàm realloc.
• Chú ý: Nhập file danh sách lớp ít nhất 10 dòng, dữ liệu đúng thực tế.
*/
#include<stdio.h>
#include<stdlib.h>

enum {SUCCESS, FAIL};
typedef struct {
    int no; // số lượng sinh viên
    char id[20]; // mã số sinh viên
    char name[50]; // họ tên sinh viên
    char phone[15]; // số điện thoại sinh viên 
} student;
int main(void) {
    FILE *fptr;
    student *arr = malloc(10 * sizeof(student)); // mảng chứa sinh viên
    int count = 0; // biến đếm số lượng sinh viên đã đọc
    int n; // biến lưu số lượng sinh viên trong file
    int reval = SUCCESS; // kết quả trả về của chương trình
    printf("Loading file ...\n");
    if((fptr = fopen("student.txt", "r")) == NULL) {
        printf("Cannot open %s.\n", "student.txt");
        reval = FAIL;
    } else {
        while(fscanf(fptr, "%d%s%s%s", &arr[count].no, arr[count].id, arr[count].name, arr[count].phone) != EOF) {
            count ++;
        }
        n = count; // lưu số lượng sinh viên đã đọc vào biến n
        for (count = 0; count < n; count ++) {
            printf("%-6d%-15s%-20s%-15s\n", arr[count].no, arr[count].id, arr[count].name, arr[count].phone);
        }
    }
    int k;
    printf("Enter the number of students to add: ");
    scanf("%d", &k);
    if(k < 0) {
        printf("Invalid number of students to add.\n");
    }
    // nhập thêm sinh viên
    arr = realloc(arr, (n + k) * sizeof(student)); // cấp phát thêm bộ nhớ cho k sinh viên
    if(arr == NULL) {
        printf("Memory allocation failed\n");
        reval = FAIL;
    } else {
        for(int i = n; i < n + k; i ++) {
            printf("Enter student %d information (no id name phone): ", i + 1);
            scanf("%d %s %s %s", &arr[i].no, arr[i].id, arr[i].name, arr[i].phone);
        }
        printf("Updated student list:\n");
        for(int i = 0; i < n + k; i ++) {
            printf("%-6d%-15s%-20s%-15s\n", arr[i].no, arr[i].id, arr[i].name, arr[i].phone);
        }
    }
    if(reval == FAIL) {
        free(arr); // giải phóng bộ nhớ nếu có lỗi
    }
    return reval;
}