/*
Ví dụ 1. Viết chương trình đọc từng dòng văn bản từ một tập tin, sau đó tính độ dài xâu
ký tự trên mỗi dòng và ghi ra một tập tin mới theo định dạng sau: <độ dài dòng> <Nội
dung dòng>
• Ví dụ, với một dòng trong tập tin đầu vào:
The quick brown fox jumps over the lazy dog.
trong tập tin đầu ra ở dòng tương ứng sẽ là:
44 The quick brown fox jumps over the lazy dog.
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_LEN 500 // Giới hạn độ dài mỗi dòng
enum {sUCCESS, FAIL};
void LineReadWrite(FILE *fin, FILE *fout) {
    char buffer[MAX_LEN]; // mảng ký tự để lưu từng dòng đọc được từ file
    int len;
    while (fgets(buffer, MAX_LEN, fin)!= NULL) {
        len = strlen(buffer); // tính độ dài của dòng
        fprintf(fout, "%d %s", len, buffer); // ghi độ dài và nội dung vào file đầu ra
        printf("%d %s", len, buffer); // show
    }
}
int main(void) {
    FILE *fptr1, *fptr2; // con trỏ FILE để mở và làm việc với 2 file
    char filename1[] = "note.txt"; 
    char filename2[] = "lab2.txt";
    int reval = sUCCESS;
    if((fptr1 = fopen(filename1, "r")) == NULL) {
        printf("Cannot open %s.\n", filename1); 
        reval = FAIL;
    } else if((fptr2 = fopen(filename2, "w")) == NULL) {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    } else {
        LineReadWrite(fptr1, fptr2); 
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}