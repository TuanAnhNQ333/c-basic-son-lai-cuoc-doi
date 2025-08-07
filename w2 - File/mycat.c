/*
Bài tập 1. Viết chương trình mycat đọc và hiển thị nội dung một tập tin văn bản trên màn
hình. Chương trình hỗ trợ hai cú pháp sử dụng như sau:
• cat <filename> : Hiển thị một lần toàn bộ nội dung
• cat <filename> -p : Hiển thị theo từng trang. Người dùng chạm một phím để xem trang
tiếp theo.
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_LEN 81
#define PAGE_SIZE 20 

enum {SUCCESS, FAIL};
void CharReadWrite(FILE *fin, FILE *fout) {
    char buffer[MAX_LEN]; 
    int count = 0; 
    while (fgets(buffer, MAX_LEN, fin) != NULL) {
        fputs(buffer, fout);
        printf("%s", buffer);
        count++;
        if(count % PAGE_SIZE == 0) {
            printf("\nPress any key to continue ... \n");
            getchar();
        }
    }
}
int main(int argc, char *argv[] ) {
    FILE *fptr;
    char *filename;
    int reval = SUCCESS;
    if(argc < 2 || argc >3) {
        printf("Usage: %s <filename> [-p] \n", argv[0]);
        return FAIL;
    }
    filename = argv[1];
    if((fptr = fopen(filename, "r")) == NULL) {
        printf("Cannot open %s.\n", filename);
        reval = FAIL;
    } else {
        if(argc == 3 && strcmp(argv[2], "-p") == 0) {
            CharReadWrite(fptr, stdout);
        } else {
            char buffer[MAX_LEN];
            while (fgets(buffer, MAX_LEN, fptr) != NULL) {
                printf("%s", buffer);
            }
        }
    }
    fclose(fptr);
    return reval;
}