/*  Viết chương trình có tên mycp hoạt động tương tự lệnh cp trong các hệ điều
hành UNIX/LINUX. Nó có thể sao chép một tập tin văn bản sang một tập tin mới theo cú
pháp:
• mycp <tập_tin_1> <tập_tin_2>
• Đường dẫn, tên các tập tin được cung cấp dưới dạng đối số dòng lệnh. */

#include<stdio.h>
#include<ctype.h>

enum {SUCCESS, FAIL};
void CharReadWrite(FILE *fin, FILE *fout) {
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
        putchar(c);
    }
}
int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return FAIL;
        
    }
    FILE *fptr1, *fptr2;
    char *filename1, *filename2;
    filename1 = argv[1];
    filename2 = argv[2];

    int reval = SUCCESS;
    if((fptr1 = fopen(filename1, "r")) == NULL) {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    } else if((fptr2 = fopen(filename2, "w")) == NULL) {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    } else {
        CharReadWrite(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}