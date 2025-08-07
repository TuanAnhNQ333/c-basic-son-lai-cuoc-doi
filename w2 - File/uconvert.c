/*
Viết chương trình có tên uconvert có chức năng chuyển đổi tất cả các chữ cái
trong nội dung một tập tin cụ thể (được cung cấp trong đối số dòng lệnh) thành chữ hoa
và ghi lại nội dung mới vào chính tập tin đó.
• Cú pháp: uconvert tata.txt
*/
#include<stdio.h>
#include<ctype.h>

enum{SUCCESS, FAIL};
void CharReadWrite(FILE *fin, FILE *fout) {
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(toupper(c), fout); // chuyển đổi chữ cái thường thành chữ hoa
        putchar(c); // hiển thị ký tự đã chuyển thành chữ hoa
    }
}
int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return FAIL;
    }
    FILE *fptr;
    char *filename = argv[1];
    int reval = SUCCESS;
    if((fptr = fopen(filename, "r+")) == NULL) { // mở file với chế độ đọc và ghi, file phải tồn tại, không xoá nội dung cũ
        printf("Cannot open %s.\n", filename);
        reval = FAIL;
    } else {
        CharReadWrite(fptr, fptr);
        fclose(fptr);
    }
    return reval;
}