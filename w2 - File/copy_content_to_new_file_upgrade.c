#include <stdio.h>
#include <stdlib.h>  // cho exit(), EXIT_FAILURE, EXIT_SUCCESS
#include <string.h>  // cho strlen()

#define MAX_FILENAME_LEN 260  // Giới hạn độ dài tên file theo chuẩn Windows/Linux

void CharReadWrite(FILE *fin, FILE *fout) {
    int c;
    while ((c = fgetc(fin)) != EOF) {
        if (fputc(c, fout) == EOF) {
            perror("Error writing to output file");
            exit(EXIT_FAILURE); // Thoát chương trình ngay nếu ghi lỗi
        }
        putchar(c);  // Hiển thị ký tự ra màn hình
    }
}

void getFileName(char *prompt, char *filename) {
    printf("%s", prompt);
    if (fgets(filename, MAX_FILENAME_LEN, stdin) == NULL) {
        fprintf(stderr, "Error reading filename.\n");
        exit(EXIT_FAILURE);
    }

    // Xóa ký tự newline nếu có
    size_t len = strlen(filename);
    if (filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
}

int main(void) {
    FILE *fptr1, *fptr2;
    char filename1[MAX_FILENAME_LEN];
    char filename2[MAX_FILENAME_LEN];

    // Nhập tên file đầu vào và đầu ra từ người dùng
    getFileName("Enter input file name: ", filename1);
    getFileName("Enter output file name: ", filename2);

    // Mở file đầu vào
    fptr1 = fopen(filename1, "r");
    if (fptr1 == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Mở file đầu ra
    fptr2 = fopen(filename2, "w");
    if (fptr2 == NULL) {
        perror("Error opening output file");
        fclose(fptr1);  // đóng file đầu vào trước khi thoát
        exit(EXIT_FAILURE);
    }

    // Thực hiện sao chép nội dung
    CharReadWrite(fptr1, fptr2);

    // Đóng file và kiểm tra lỗi khi đóng
    if (fclose(fptr1) != 0) {
        perror("Error closing input file");
    }
    if (fclose(fptr2) != 0) {
        perror("Error closing output file");
    }

    printf("\nCopy completed successfully.\n");

    return EXIT_SUCCESS;
}
