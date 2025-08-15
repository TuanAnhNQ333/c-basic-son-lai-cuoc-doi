#include <stdio.h>              // Bao gồm các hàm nhập/xuất chuẩn (ví dụ: printf, fopen)
#include <stdlib.h>             // Bao gồm các hàm thư viện chuẩn (ví dụ: exit)

#define MAX_LEN 8000            // Định nghĩa hằng số cho độ dài bộ đệm tối đa

enum { SUCCESS, FAIL };         // Định nghĩa enum vô danh cho giá trị trả về (SUCCESS=0, FAIL=1)

int main() {                    // Điểm bắt đầu của chương trình
    int num;                    // Khai báo biến nguyên để lưu số byte đã đọc
    int reval = SUCCESS;        // Khởi tạo giá trị trả về là SUCCESS
    FILE *fptr2;                // Khai báo con trỏ tệp để thao tác với tệp
    char filename2[] = "student.txt"; // Khai báo và khởi tạo tên tệp cần mở
    char buffer[MAX_LEN + 1];   // Khai báo bộ đệm để lưu nội dung tệp (+1 cho ký tự kết thúc chuỗi)

    if ((fptr2 = fopen(filename2, "r")) == NULL) { // Thử mở tệp để đọc
        printf("Không thể mở tệp %s.\n", filename2); // In thông báo lỗi nếu không mở được tệp
        reval = FAIL;           // Đặt giá trị trả về là FAIL
        exit(1);                // Thoát chương trình với mã lỗi 1
    }

    num = fread(buffer, sizeof(char), MAX_LEN, fptr2); // Đọc tối đa MAX_LEN byte từ tệp vào bộ đệm
    buffer[num] = '\0';         // Thêm ký tự kết thúc chuỗi để tạo thành chuỗi hợp lệ trong C
    printf("%s", buffer);       // In nội dung bộ đệm ra màn hình

    fclose(fptr2);              // Đóng tệp
    return reval;               // Trả về trạng thái chương trình (SUCCESS hoặc FAIL)
}
