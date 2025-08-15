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
    student *arr = NULL;
    int n = 0, k, reval = SUCCESS;

    if ((fptr = fopen("student.txt", "r")) == NULL) {
        printf("Cannot open file.\n");
        return FAIL;
    }

    // Đếm số sinh viên
    student temp;
    while (fscanf(fptr, "%d %s %s %s", &temp.no, temp.id, temp.name, temp.phone) == 4) {
        n++;
    }
    rewind(fptr); // rewind : 

    // Cấp phát đúng kích thước
    arr = malloc(n * sizeof(student));
    for (int i = 0; i < n; i++) {
        fscanf(fptr, "%d %s %s %s", &arr[i].no, arr[i].id, arr[i].name, arr[i].phone);
    }
    fclose(fptr);

    printf("Current students:\n");
    for (int i = 0; i < n; i++) {
        printf("%-6d%-15s%-20s%-15s\n", arr[i].no, arr[i].id, arr[i].name, arr[i].phone);
    }

    // Nhập thêm sinh viên
    printf("Enter the number of students to add: ");
    scanf("%d", &k);
    arr = realloc(arr, (n + k) * sizeof(student));
    for (int i = n; i < n + k; i++) {
        printf("Enter student %d (no id name phone): ", i + 1);
        scanf("%d %s %s %s", &arr[i].no, arr[i].id, arr[i].name, arr[i].phone);
    }

    printf("\nUpdated list:\n");
    for (int i = 0; i < n + k; i++) {
        printf("%-6d%-15s%-20s%-15s\n", arr[i].no, arr[i].id, arr[i].name, arr[i].phone);
    }

    free(arr);
    return reval;
} 