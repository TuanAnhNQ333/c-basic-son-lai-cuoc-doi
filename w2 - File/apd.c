/*Viết chương trình nhận tên hai tập tin ở đối số dòng lệnh, sau đó tiến hành
ghép nội dung của tập tin thứ hai vào cuối tập tin thứ nhất. Giả sử cả hai tập tin đều tồn
tại.
• Cú pháp sử dụng:
• apd <file1> <file2>
*/
#include<stdio.h>

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
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return FAIL;
    }
    
    FILE *fptr1, *fptr2;
    char *filename1, *filename2;
    filename1 = argv[1];
    filename2 = argv[2];

    int reval = SUCCESS;
    if((fptr1 = fopen(filename1, "a")) == NULL) {
        printf("Cannot open %s for appending.\n", filename1);
        reval = FAIL;
    } else if((fptr2 = fopen(filename2, "r")) == NULL) {
        printf("Cannot open %s for reading.\n", filename2);
        reval = FAIL;
    } else {
        CharReadWrite(fptr2, fptr1);
        fclose(fptr2);
        fclose(fptr1);
    }
    return reval;
}