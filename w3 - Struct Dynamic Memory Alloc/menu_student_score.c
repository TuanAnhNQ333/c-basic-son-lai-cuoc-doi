
/*
Viết chương trình đọc tập tin bảng điểm (bangdiem.txt kết quả của bài tập về
danh sách sinh viên và bảng điểm đã cho) và lưu trữ dữ liệu sử dụng bộ nhớ động, sau đó
ghi chúng ra tập tin nhị phân grade.dat (chứa mảng các phần tử kiểu cấu trúc về sinh
viên).

• Chương trình có thể: đọc file grade.dat và hiển thị bảng điểm trên màn hình, tìm kiếm
một sinh viên dựa trên mã số sinh viên và cập nhật điểm mới nhập từ người dùng và lưu
vào tập tin.

• Chương trình nên được viết với tương tác menu dòng lệnh:
1. TextToDat
2. Display Dat file
3. Search and Update.
4. Quit.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {SUCCESS, FAIL};

typedef struct student_t {
    char id[10];
    char name[30];
    double score;
} student;

void TextToDat(const char *txtFile, const char *datFile) {
    FILE *fin = fopen(txtFile, "r");
    FILE *fout = fopen(datFile, "w+b");
    if(!fin || !fout) {
        printf("Cannot open file.\n");
        return;
    }
    student s;
    while(fscanf(fin, "%s %s %lf", s.id, s.name, &s.score) == 3) {
        fwrite(&s, sizeof(student), 1, fout);
    }

    fclose(fin);
    fclose(fout);
    printf("Converted %s to %s successfully.\n", txtFile, datFile);
}

void DisplayDat(const char *datFile) {
    FILE *fin = fopen(datFile, "rb");
    if(!fin) {
        printf("Cannot open file %s.\n", datFile);
        return;
    }
    student s;
    printf("---- Grade List ----\n");
    while(fread(&s, sizeof(student), 1, fin) == 1) {
        printf("ID: %s, Name: %s, Score: %.2lf\n", s.id, s.name, s.score);
    }
    fclose(fin);
}

void SearchAndUpdate(const char *datFile) {
    FILE *fin = fopen(datFile, "rb");
    FILE *fout = fopen("temp.dat", "wb");
    if(!fin || !fout) {
        printf("Cannot open file %s.\n", datFile);
        return;
    }

    char search_id[10];
    double new_score;
    int found = 0;
    student s;

    printf("Enter student ID to search: ");
    scanf("%s", search_id);

    while(fread(&s, sizeof(student), 1, fin) == 1) {
        if(strcmp(s.id, search_id) == 0) {
            found = 1;
            printf("Found student: ID: %s, Name: %s, Score: %lf\n", s.id, s.name, s.score);
            printf("Enter new score: ");
            scanf("%lf", &new_score);
            s.score = new_score;
        } 
        fwrite(&s, sizeof(student), 1, fout);
        
    }
    fclose(fin);
    fclose(fout);
    remove(datFile);
    rename("temp.dat", datFile);

    if(found) {
        printf("Updated successfully.\n");
    } else {
        printf("Student ID not found.\n");
    }
}

int main(void) {
    char txtFile[] = "bangdiem.txt";
    char datFile[] = "grade.dat";
    int choice;

    do {
        printf("Menu:\n");
        printf("1. TextToDat\n");
        printf("2. Display Dat file\n");
        printf("3. Search and update\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                TextToDat(txtFile, datFile);
                break;
            case 2:
                DisplayDat(datFile);
                break;
            case 3:
                SearchAndUpdate(datFile);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return SUCCESS;
}