/* 
Viết chương trình sao chép tập tin (từ lab1.txt sang lab1a.txt) tương tự các bài
tập trước nhưng sử dụng các thao tác đọc ghi tập tin theo khối dữ liệu.
• Sử dụng các hàm: fread, fwrite, feof
*/
#include<stdio.h>
#include<stdlib.h>
enum{SUCCESS, FAIL};

#define MAX_LEN 8000 // Định nghĩa hằng số cho độ dài bộ đệm tối đa
void BlockReadWrite(FILE *fin, FILE *fout) {
    int num; // Biến để lưu số byte đã đọc
    char buffer[MAX_LEN + 1]; // Bộ đệm để lưu nội dung tệp

    while(!feof(fin)) {
        num = fread(buffer, sizeof(char), MAX_LEN, fin); // đọc tối đa MAX_LEN byte từ tệp fin
        buffer[num *sizeof(char)] = '\0'; // Thêm ký tự kết thúc chuỗi

        printf("%s", buffer); // in 
        fwrite(buffer, sizeof(char), num, fout); // ghi nội dung fin vào fout
    }
}

int main(void) {
    FILE *fptr1, *fptr2;
    char filename1[] = "student.txt"; // Tên tệp nguồn
    char filename2[] = "student_copy.txt"; // Tên tệp đích
    int reval = SUCCESS;
    if((fptr1 = fopen(filename1, "r")) == NULL) {
        printf("Cannot open file %s.\n", filename1);
        reval = FAIL;
    } else if((fptr2 = fopen(filename2, "w")) == NULL) {
        printf("Cannot open file %s.\n", filename2);
        reval = FAIL;
    } else {
        BlockReadWrite(fptr1, fptr2); // Gọi hàm để sao chép nội dung từ tệp nguồn sang tệp đích
        fclose(fptr1); // close
        fclose(fptr2);
    }
    printf("\n");
    return reval; 
}