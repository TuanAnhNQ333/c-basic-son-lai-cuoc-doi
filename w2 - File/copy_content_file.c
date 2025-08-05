/*
Tạo 1 file văn bản tên : note.txt với nội dung : lý thuyết file, lưu trong cùng thư mục với prog
Viết chương trình đọc từ file trên mỗi lần 1 ký tự, sau đó ghi vào file mới với tên : lab1.txt
*/
#include<stdio.h>

enum{SUCCESS, FAIL};
void CharReadWrite(FILE *fin, FILE *fout) {
    int c;
    while((c = fgetc(fin))!= EOF) {
        fputc(c, fout); // write to a file
        putchar(c); // display character on the screen
    }
}
int main (void) {
    FILE *fptr1, *fptr2;
    char filename1[] = "note.txt";
    char filename2[] = "lab1.txt";
    int reval = SUCCESS;

    if ((fptr1 = fopen(filename1, "r")) == NULL) {
        printf("Cannot open %s. \n", filename1);
        reval = FAIL;
    }
    else if ((fptr2 = fopen(filename2, "w")) == NULL) {
        printf("Cannot open %s. \n", filename2);
        reval = FAIL;
    }
    else {
        CharReadWrite(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;

}