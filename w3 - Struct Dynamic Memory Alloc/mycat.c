/*
Ví dụ 2. Viết chương trình mycat có chức năng tương tự lệnh cat trong Unix sử dụng kỹ thuật vào ra
theo khối dữ liệu. cat : đọc nội dung và in ra màn hình, dùng đối số dòng lệnh argv argc
• Gợi ý:
• Nhận đối số dòng lệnh
• Dùng hàm fread

*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 100

enum {SUCCESS, FAIL};
void BlockCat(FILE *fin) {
    int num; // biến lưu số byte đã đọc
    char buffer[MAX_LEN + 1]; // 

    while ((!feof(fin))) {
        num = fread(buffer, sizeof(char), MAX_LEN, fin); // 
        buffer[num * sizeof(char)] = '\0'; 
        printf("%s", buffer);
    }
}
int main(int argc, char *argv[]) {
    FILE *fptr;
    int reval = SUCCESS;
    if(argc != 2) {
        printf("The correct syntax should be: cat1 filename\n");
        reval = FAIL;
    }
    if((fptr = fopen(argv[1], "r")) == NULL ) {
        printf("Cannot open file %s.\n", argv[1]);
        reval = FAIL;
    } else {
        BlockCat(fptr); 
        fclose(fptr);
    }
    return reval;
}