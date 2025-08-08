/*Tạo một file văn bản nội dung là danh sách lớp gồm ít nhất 6 sinh viên. Mỗi
dòng gồm 4 trường sau:
• STT(số thứ tự) Mã số sinh viên Họ và tên (không chứa ký tự trắng) Số điện thoại. Ví dụ
• 1 20181110 Bui_Van 0903112234
• 2 20182111 Joshua_Kim 0912123232
• Viết chương trình đọc tập tin trên vào một mảng các cấu trúc phù hợp. Chương trình yêu
cầu nhập bổ sung thêm trường điểm cho mỗi sinh viên sau đó ghi lại kết quả vào tập tin
bangdiem.txt (transcript.txt) gồm tất cả các trường nói trên (cùng trường điểm).
*/
#include<stdio.h>
enum {SUCCESS, FAIL};
#define MAX_ELEMENT 100 // giới hạn số lượng sinh viên trong mảng
typedef struct {
    int no; // số lượng sinh viên
    char id[20]; // mã số sinh viên
    char name[50]; // họ tên sinh viên
    char phone[15]; // số điện thoại sinh viên 
} student;
int main(void) {
    FILE *fptr;
    student arr[MAX_ELEMENT]; // mảng chứa sinh viên
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
    fclose(fptr);
    return reval;
}