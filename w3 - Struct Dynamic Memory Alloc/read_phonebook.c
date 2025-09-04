/*
Viết chương trình đọc một phần cụ thể trong dữ liệu danh bạ lưu trữ trong tập
tin phonebook.dat. Ví dụ từ dữ liệu danh bạ (bản ghi) thứ 2 đến thứ 3, hay từ thứ 3 đến
thứ 6. Sau đó thay đổi giá trị trường email và ghi lại vào tập tin ở đúng vị trí đã trích xuất.
• Chương trình cần cấp phát bộ nhớ để lưu trữ đúng lượng dữ liệu đọc ra từ tập tin khi
chạy chương trình. Ví dụ cần mảng động với 4 phần tử cấu trúc để lưu dữ liệu từ phần tử
thứ 3 đến thứ 6.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {SUCCESS, FAIL} ;
#define MAX_ELEMENT 20
// phone book structure
typedef struct phoneaddress {
    char name[20];
    char telephone[11];
    char email[25];
} phoneaddress;
int main(void) {
    FILE *fp;
    phoneaddress *phonearr;

    int i, n, irc;
    int reval = SUCCESS;
    printf("Read from 2nd data to 3rd data\n");
    if((fp = fopen("phonebook.dat", "r+b")) == NULL) {
        printf("Cannot open file %s.\n", "phonebook.dat");
        reval = FAIL;
    } 
    // memory allocation
    phonearr = (phoneaddress*)malloc(MAX_ELEMENT * sizeof(phoneaddress));
    if(phonearr == NULL) {
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    if(fseek(fp, 1 * sizeof(phoneaddress), SEEK_SET) != 0) {
        printf("Seek failed!\n");
        return FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), 2, fp);
    for(i = 0; i < 2; i ++) {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].telephone);
        printf("%s\n", phonearr[i].email);
    }
    // modifying some data
    strcpy(phonearr[1].name, "Lan Hoa");
    strcpy(phonearr[1].telephone, "0987654321");
    strcpy(phonearr[1].email, "lanhoa@example.com");
    // write back to file
    fseek(fp, 1 * sizeof(phoneaddress), SEEK_SET);
    irc = fwrite(phonearr, sizeof(phoneaddress), 2, fp);
    printf("fwrite return code = %d\n", irc);
    fclose(fp);
    free(phonearr); // free allocated memory
    return reval;
}