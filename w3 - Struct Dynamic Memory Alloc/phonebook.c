/*
Đọc và ghi tập tin nhị phân chứa các cấu trúc
 Giả sử bạn cần quản lý một danh bạ điện thoại của mình bằng chương trình.
  Định nghĩa một cấu trúc biểu diễn danh bạ gồm các trường "name," "telephone number," "e-mail address,” và khai báo một mảng chứa tối đa 100 phần tử thuộc kiểu cấu trúc trên.
• Nhập liệu cho khoảng 10 phần tử mảng.
• Chương trình sau đó ghi nội dung mảng với các phần tử nói trên vào tập tin có tên
phonebook.dat sử dụng hàm fwrite.
• Đọc lại dữ liệu từ tập tin vào mảng sử dụng hàm fread và in nội dung mảng ra màn hình 

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {SUCCESS, FAIL};
#define MAX_LEN 100

typedef struct phoneaddress_t {
    char name[20];
    char telephone[15];
    char email[30];

} phoneaddress;
int main(void) {
    FILE *fp;
    phoneaddress phonearr[MAX_LEN];
    int i, n, irc;
    int reval = SUCCESS;

    printf("How many contacts do you want to enter (<20)?");
    scanf("%d", &n);
    for(i = 0; i < n; i ++) {
        printf("name:");
        scanf("%s", phonearr[i].name);
        printf("telephone:");
        scanf("%s", phonearr[i].telephone);
        printf("email:");
        scanf("%s", phonearr[i].email);
    }
    if((fp = fopen("phonebook.dat", "w+b")) == NULL) {
        printf("Cannot open file %s.\n", "phonebook.dat");
        reval = FAIL;
    }
    irc = fwrite(phonearr, sizeof(phoneaddress), n, fp);
    printf("fwrite return code = %d\n", irc);
    fclose(fp);
    // read from this file to array again
    if((fp = fopen("phonebook.dat", "rb")) == NULL) {
        printf("Cannot open file %s.\n", "phonebook.dat");
        reval = FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), n, fp);
    printf(" fread return code = %d\n", irc);
    for(i = 0; i < n; i ++) {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].telephone);
        printf("%s\n",phonearr[i].email);
    }
    fclose(fp);
    return reval;

}