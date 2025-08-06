/*
Bài tập 4. Viết một chương trình có thể sử dụng cùng một lúc hai chức năng mã hóa và
giải mã một tập tin văn bản sử dụng mật mã Caesar (mã hóa cộng) như sau. Chương trình
nhận ba đối số:
• <tập tin nguồn> <độ dịch chuyển> < tập tin đích>
• Khi cần mã hóa, chạy chương trình với độ dịch chuyển (offset) n là một số nguyên dương.
Chương trình sẽ thay thế mỗi ký tự trong tập tin bởi một ký tự đứng sau nó n vị trí trong
bảng mã ASCII. Ví dụ với offset =3 thì AD, B E
• Khi giải mã, chạy chương trình với đầu vào là tập tin mã hóa và giá trị độ dịch chuyển là số
âm tương ứng (VD offset = -3)
• Chức năng nâng cao (tùy chọn): Với các ký tự là chữ cái thực hiện dịch chuyển vòng tròn:
A-> D, ..., Z -> C
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
enum {SUCCESS, FAIL};
void CharCaesar(FILE *fin, FILE *fout, int offset) {
    int c;
    while ((c = fgetc(fin)) != EOF) { // đọc từng ký tự từ file cho đến khi gặp EOF
        if(isalpha(c)) { // hàm isalpha : là hàm kiểm tra xem ký tự có phải là chữ cái hay không
            if(isupper(c)) { // hàm issupper : kiểm tra xem có phải là ký tự in hoa
                c = ((c - 'A' + offset) % 26 + 26) %26 + 'A';
                /*
                giải thích biểu thức : (c - 'A') -> chuyển ký tự sang số : 0 - 25
                + offset : dịch ký tự theo mã caesar
                % 26 : --> quay vòng trong bảng chữ cái
                + 26 và % 26 : -> đảm bảo kết quả dương nếu offset âm
                + 'A' : chuyển ngược về mã ascii của ký tự in hoa 
                */

            }
            else if(islower(c)) { // nếu là chữ cái in thường 
                c = ((c - 'a' + offset) %26 + 26) %26 + 'a';
                /*
                giải thích biểu thức : (c - 'a') -> chuyển ký tự sang số : 0 - 25
                + offset : dịch ký tự theo mã caesar
                % 26 : --> quay vòng trong bảng chữ cái
                + 26 và % 26 : -> đảm bảo kết quả dương nếu offset âm
                + 'a' : chuyển ngược về mã ascii của ký tự in thường
                */
            }

        }
        fputc(c, fout); // ghi ký tự đã xử lý vào file đầu ra 

        putchar(c); // in ra màn hình để hiển thị kết quả 
    }
}
int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s <source_file> <offset> <destination_file>\n", argv[0]);
        return FAIL;
    }

    FILE *fptr1, *fptr2;
    char *filename1, *filename2;
    filename1 = argv[1];
    int offset = atoi(argv[2]);
    filename2 = argv[3];
    
    int reval = SUCCESS;
    if((fptr1 = fopen(filename1, "r")) == NULL) {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    } else if((fptr2 = fopen(filename2, "w")) == NULL) {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    } else {
        CharCaesar(fptr1, fptr2, offset);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}