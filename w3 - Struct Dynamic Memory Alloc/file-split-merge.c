/*
Bài tập 3. Chia tách và ghép File
Sử dụng tập tin phonebook.dat (kết quả của bài tập trên Lab) chứa ít nhất 20 số liên lạc. Viết các
chương trình sau
• Chương trình filesplit nhận hai đối số: tên file nguồn (.dat) và một số nguyên N và tên hai file kết
quả. Nó sẽ tách file nguồn thành 2 file, trong đó file đầu tiên chứa N số liên lạc đầu tiên và file thứ
hai chứa các số liên lạc còn lại. Ví du
    filesplit phone.dat 10 phone1.dat phone2.dat
• Chương trình filemerge ghép hai file đã tách thành một file:
    filemerge phone1.dat phone2.dat phone.dat
• Chương trình fileread đọc và hiển thị danh sách các số liên lạc chứa trong một file .dat bất kỳ ra
màn hình. Nó được sử dụng để kiểm tra kết quả thực hiện các chương trình filesplit and filemerge.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {SUCCESS, FAIL};
#define MAX_LEN 100
#define MAX_LINE 512

typedef struct PhoneInfo_t {
    char name[20];
    char telephone[15];
    char email[30];

} PhoneInfo;
/*• Chương trình filesplit nhận hai đối số: tên file nguồn (.dat) và một số nguyên N và tên hai file kết
quả. Nó sẽ tách file nguồn thành 2 file, trong đó file đầu tiên chứa N số liên lạc đầu tiên và file thứ
hai chứa các số liên lạc còn lại. Ví du
• filesplit phone.dat 10 phone1.dat phone2.dat*/
void filesplit(const char *input_file, int n, const char *output_file1, const char *output_file2) {
    FILE *fin = fopen(input_file, "rb");
    if(fin == NULL) {
        printf("Cannot open input file %s!", input_file);
        return;
    }
    FILE *fout1 = fopen(output_file1, "wb");
    FILE *fout2 = fopen(output_file2, "wb");
    if(fout1 == NULL) {
        printf("Cannot open first output file %s", output_file1);
        return;
    }
    if(fout2 == NULL) {
        printf("Cannot open second output file %s", output_file2);
        return;
    }

    char line[MAX_LINE];
    PhoneInfo info;
    int count = 0;

    while(fread(&info, sizeof(PhoneInfo), 1, fin) == 1) {
        if(count < n) {
            fwrite(&info, sizeof(PhoneInfo), 1, fout1);
        } else {
            fwrite(&info, sizeof(PhoneInfo), 1, fout2);
        }
        count ++;
    }
    fclose(fin);
    fclose(fout1);
    fclose(fout2);
}
/*• Chương trình filemerge ghép hai file đã tách thành một file:
• filemerge phone1.dat phone2.dat phone.dat*/
void filemerge(const char *input_file1, const char *input_file2, const char *output_file) {
    FILE *file1 = fopen(input_file1, "rb");
    FILE *file2 = fopen(input_file2, "rb");
    FILE *fileout = fopen(output_file, "rb");
    if(file1 == NULL) {
        printf("Cannot open file %s", input_file1);
        return;
    }
    if(file2 == NULL) {
        printf("Cannot open file %s", input_file2);
        return;
    }
    if(fileout == NULL) {
        printf("Cannot open file %s", output_file);
        return;
    }

    PhoneInfo info;
    while(fread(&info, sizeof(PhoneInfo), 1, file1) == 1) {
        fwrite(&info, sizeof(PhoneInfo), 1, fileout);
    }
    while(fread(&info, sizeof(PhoneInfo), 1, file2) == 1) {
        fwrite(&info, sizeof(PhoneInfo), 1, fileout);
    }
    
    fclose(file1);
    fclose(file2);
    fclose(fileout);

}
/*• Chương trình fileread đọc và hiển thị danh sách các số liên lạc chứa trong một file .dat bất kỳ ra
màn hình. Nó được sử dụng để kiểm tra kết quả thực hiện các chương trình filesplit and filemerge.*/
void fileread(const char *filename) {
    FILE *fin = fopen(filename, "rb");
    if(fin == NULL) {
        printf("Cannot open file %s", filename);
        return;
    }
    PhoneInfo info;
    int index = 1;
    while(fread(&info, sizeof(PhoneInfo), 1, fin) == 1) {
        printf("%2d. Name: %-20s | Phone: %-20s | Email: %-20s", index, info.name, info.telephone, info.email);
        index ++;
    }
    fclose(fin);
}

int main(int argc, char *argv[]) {
    FILE *fptr;
    if(argc != 2) {
        printf("The correct syntax should be: \n");
        printf(" %s filesplit <src> <N> <fileout1> <fileout2> \n", argv[0]);
        printf(" %s filemerge <src1> <src2> <fileout>\n", argv[0]);
        printf(" %s fileread <filename>\n", argv[0]);
        return 1;
    }
    if(strcmp(argv[1], "filesplit") == 0) {
        if(argc != 6) {
            printf("The correct syntax should be : %s filesplit <src> <N> <fileout1> <fileout2>\n", argv[0]);
            return 1;
        }
        int N = atoi(argv[3]);
        filesplit(argv[2], N , argv[4], argv[5]);
    } else if (strcmp(argv[1], "filemerge") == 0) {
        if(argc != 5) {
            printf("The correct syntax should be : %s filemerge <file1> <file2> <fileout>\n", argv[0]);
            return 1;
        }
        filemerge(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "fileread") == 0) {
        if(argc != 3) {
            printf("The correct syntax should be : %s fileread <filename>\n", argv[0]);
            return 1;
        }
        fileread(argv[2]);
    } else {
        printf("Unknown command %s\n", argv[1]);
    }
    return 0;

}