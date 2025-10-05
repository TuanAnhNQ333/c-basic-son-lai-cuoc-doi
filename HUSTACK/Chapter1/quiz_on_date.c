/*Cần thống kê xem mỗi ngày có bao nhiêu lượt sinh viên làm trắc nghiệm.
Input
Thông tin về sinh viên làm trắc nghiệm ôn tập được cho theo các dòng định dạng như sau:
<yyyy-mm-dd> <hh:mm:ss> <user_id> <question_id>: trong đó sinh viên có mã <user_id> làm câu hỏi <question_id> vào ngày giờ là <yyyy-mm-dd> <hh:mm:ss>
Kết thúc dữ liệu là 1 dòng chứa dấu *
Output
Mỗi dòng ghi <yyyy-mm-dd> <cnt>: trong đó <cnt> là số lượt sinh viên làm trắc nghiệm trong ngày <yyyy-mm-dd>
(chú ý: các dòng được sắp xếp theo thứ tự tăng dần của ngày thống kê, ngày thống kê nào mà không có lượt sinh viên làm trắc nghiệm thì không in ra)
Example
Input
2022-01-02 10:30:24 dungpq question1
2022-01-03 11:30:24 dungpq question1
2022-02-01 03:30:20 viettq question2
2022-02-01 03:35:20 viettq question1
2022-03-01 03:30:20 viettq question7
2022-01-02 11:20:24 viettq question2
*
Output
2022-01-02 2
2022-01-03 1
2022-02-01 2
2022-03-01 1*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxlen 1000
#define datelen 11

typedef struct student_id {
    char date[datelen];
    char user_id;
    char question_id;
    int count;
} infomation;
int main() {
    infomation info[maxlen];
    int n = 0;
    char line[200];

    while(1) {
        fgets(line, sizeof(line), stdin);
        if(line[0] == '*') {
            break;
        }
        char date[11];
        strncpy(date, line, 10);
        date[10] = '\0';
        int found = 0;
        for(int i = 0; i < n; i ++) {
            if(strcmp(info[i].date, date) == 0) {
                info[i].count ++;
                found = 1;
                break;
            }
        }
        if(!found) {
            strcpy(info[n].date, date);
            info[n].count = 1;
            n ++;
        }
    }
    for(int i = 0; i < n - 1; i ++) {
        for(int j = i + 1; j < n; j ++) {
            if(strcmp(info[i].date, info[j].date) > 0) {
                infomation temp = info[i];
                info[i] = info[j];
                info[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        printf("%s %d\n", info[i].date, info[i].count);

    }
    return 0;
}