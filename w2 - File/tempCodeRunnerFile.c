/*
Thực hiện lại bài tập lập trình sao chép nội dung tập tin, tuy nhiên thay vì sử dụng
cặp hàm fgetc và fputc – ta sử dụng cặp hàm fgets và fputs để đọc từ tập tin và ghi vào
tập tin mỗi lần một dòng trong nội dung văn bản.
*/

#include<stdio.h>

enum {SUCCESS, FAIL};
#define MAX_LEN 81

void LineReadWrite(FILE *fin, FILE *fout) {
    char buffer[MAX_LEN]; // mảng ký tự để lưu từng dòng đọc được từ file
    while(fgets(buffer, MAX_LEN, fin) != NULL) { // đọc từng dòng từ file fin
        fputs(buffer, fout); // ghi dòng đã đọc vào file fout
        printf("%s", buffer); // in ra màn hình để hiển thị kết quả
    }
}

int main(void ) {
    FILE *fptr1, *fptr2; // con trỏ FILE để mở và làm việc với 2 file
    char filename1[] = "note.txt"; // file fin
    char filename2[] = "lab1.txt"; // file fout
    int reval = SUCCESS; // biến lưu kết quả trả về của chương trình 

    if ((fptr1 = fopen(filename1, "r")) == NULL ) {
        printf("Cannot open %s.\n", filename1); // nếu không mở được file fin thì báo lỗi 
        reval = FAIL; 
    } else if ((fptr2 = fopen(filename2, "w")) == NULL ) {
        printf("Cannot open %s.\n", filename2); // nếu không mở được file fout thì báo lỗi 
        reval = FAIL;
    } else {
        LineReadWrite(fptr1, fptr2); // gọi hàm để sao chép nội dung file và in
        fclose(fptr1); // đóng file fin
        fclose(fptr2); // đóng file fout
    }
    return reval; // 
}