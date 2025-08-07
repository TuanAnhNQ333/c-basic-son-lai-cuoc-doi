/*Bài tập 2. Viết chương trình nhận đối số dòng lệnh là đường dẫn đến một file văn bản
(nội dung dưới 80 dòng). Chương trình thêm một dòng mới vào cuối file nói trên với nội
dung chứa các ký tự đầu tiên của các dòng trong file ban đầu.
*/
#include<stdio.h>
#include<ctype.h>

#define MAX_LEN 500
enum {SUCCESS, FAIL};
void ReadFistChars(FILE *fin, char *first_chars, int *count) {
    char buffer[MAX_LEN];
    *count = 0; // dem so dong
    while (fgets(buffer, MAX_LEN, fin) != NULL) {
        if(buffer[0] != '\n' && buffer[0] != '\0') {
            char c = buffer[0]; // lấy ký tự đầu tiên của dòng
            if(isalpha(c)) {// kiểm tra xem có phải chữ cái không
                first_chars[*count] = toupper(c); // chuyển sang chữ hoa và lưu vào mảng
            } else {
                first_chars[*count] = c; // nếu không phải chữ cái thì lưu nguyên 
            }
            (*count) ++; // tăng số dòng đã đọc 
        }
    }
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return FAIL;
    }
    FILE *fptr;
    char *filename = argv[1];
    char first_chars[500]; // mảng lưu ký tự đầu tiên của mỗi dòng
    int count = 0; // biến đếm số dòng
    int reval = SUCCESS;
    if((fptr = fopen(filename, "r")) == NULL) {
        printf("Cannot open %s for reading.\n", filename);
        return FAIL;
    }
    ReadFistChars(fptr, first_chars, &count); // đọc các ký tự đầu tiên của mỗi dòng
    fclose(fptr); 
  
    if(count > 0) {
        first_chars[count] = '\0'; // kết thúc chuỗi ký tự đầu tiên
        if((fptr = fopen(filename, "a")) == NULL) {
            printf("Cannot open %s for appending.\n", filename);
            return FAIL;
        }

        fprintf(fptr, "\n%s\n", first_chars); // ghi dòng mới vào cuối file
        fclose(fptr);
    } else {
        printf("No valid lines found in the file.\n");
    }
    
    return reval;
}