/*
Quản lý thông tin mô tả điện thoại di động
Từ các trang web của các showroom điện thoại di động, xây dựng một tập tin văn bản có tên
PhoneDB.txt chứa thông tin về ít nhất 20 mẫu điện thoại gần đây như iPhone, Samsung, Oppo,
Huawei, mỗi điện thoại một dòng.. theo định dạng sau
• Model     Memory Space (GB)       Screen Size (inches)        Price
• Viết chương trình có giao diện menu như sau:
1. Import DB from text: Đọc file PhoneDB.txt và chuyển thành định dạng nhị phân PhoneDB.dat
sử dụng kỹ thuật cấp phát động bộ nhớ.
2. Import from DB: Đọc dữ liệu từ file PhoneDB.dat và nạp vào bộ nhớ chương trình. Cho phép
người dùng lựa chọn hai chế độ đọc: Đọc toàn bộ và đọc một phần (chỉ định vị trí bản ghi bắt đầu
và kết thúc).
3. Print All Database: Hiển thị dữ liệu về các mẫu điện thoại trên màn hình, mỗi mẫu một dòng và
căn thẳng các cột.
4. Search by phone by Phone Model: Tìm kiếm điện thoại dựa trên model do người dùng nhập.
5. Exit
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 80
#define MAX_SIZE 20
#define MAX_LINE 512

typedef struct PhoneINfo_t{
    char Model[MAX_SIZE];
    int MemorySpace;
    double ScreenSize;
    char Price[MAX_SIZE];

} PhoneInfo;
enum{SUCCESS, FAIL};
// function import text to binary file
void import_DB_from_text (const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "r");
    if(fin == NULL) {
        printf("Cannot open input file %s!", input_file);
        return ;
    }
    FILE *fout = fopen(output_file, "w+b");
    if(fout == NULL) {
        printf("Cannot open output file %s!", output_file);
        fclose(fin);
        return;
    }

    char line[MAX_LINE];
    PhoneInfo info;
    
    
    while(fgets(line, sizeof(line), fin)) {
        if(sscanf(line, "%s %d %lf %s", info.Model, &info.MemorySpace, &info.ScreenSize, info.Price) == 4)  {
            fwrite(&info, sizeof(PhoneInfo), 1, fout);
        }
    }

    fclose(fin);
    fclose(fout);
    printf("Converted %s -> %s succcessfully.\n", input_file, output_file);
}
// function read all or 1 part of binary file
void import_from_DB (const char *input_file) {
    

}
// function print all DB : ok
void print_all_DB(const char *input_file) {
    PhoneInfo info;
    FILE *fin = fopen(input_file, "r");
    if(!fin) {
        printf("Cannot open file %s!", input_file);
        return ;
    }
    char line[MAX_LINE];
    while(fgets(line, sizeof(line), fin)) {
        if(sscanf(line, "%s %d %lf %s", info.Model, &info.MemorySpace, &info.ScreenSize, info.Price) == 4) {
            printf("%-20s %-10d %-10.1f %-10s\n", info.Model, info.MemorySpace, info.ScreenSize, info.Price);
        }
    }
    fclose(fin);
}
void search_by_model(const char *input_file) {
    PhoneInfo p;
    int found = 0;
    char search_model[20];
    FILE *fin = fopen(input_file, "rb");
    if(!fin) {
        printf("Cannot open file %s\n", input_file);
        return;
    }
    printf("Search model : ");
    fgets(search_model, sizeof(search_model), stdin);
    while (fread(&p, sizeof(PhoneInfo), 1, fin) == 1) {
        if(strcmp(search_model, p.Model) == 0) {
            found = 1;
            printf("Find your product : \n");
            printf("%-15s %-10d %-10.1f %-15s\n", p.Model, p.MemorySpace, p.ScreenSize, p.Price);
        }
    }
    if(!found) {
        printf("Product not found! \n");
    }
}
int main(void) {
    const char input_file[] = "PhoneDB.txt";
    const char output_file[] = "PhoneDB.dat";
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Import DB from text\n");
        printf("2. Import from DB\n");
        printf("3. Print All DB\n");
        printf("4. Search phone by phone model\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            continue;
        }
        switch(choice) {
            case 1: 
                import_DB_from_text(input_file, output_file);
                break;
            case 2: 
                import_from_DB(input_file);
                break;
            case 3: 
                print_all_DB(input_file);
                break;
            case 4:
                search_by_model(input_file);
                break;
            case 5: 
                printf("Exiting program.\n");
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return SUCCESS;
}
