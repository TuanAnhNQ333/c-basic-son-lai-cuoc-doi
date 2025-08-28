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

#define MAX_SIZE 50
#define MAX_LINE 512

typedef struct PhoneINfo_t{
    char Model[MAX_SIZE];
    int MemorySpace;
    double ScreenSize;
    char Price[MAX_SIZE];

} PhoneInfo;

enum{SUCCESS, FAIL};
/*-------------------------------------------------*/
//1. Chuyển từ file text sang file binary
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

    while(fgets(line, sizeof(line), fin)) { // lặp đến khi kết quả trong ngoặc là fail 
        //parse chuỗi line để lấy ra 4 trường của struct, so sánh với 4 để đảm bảo đọc đủ
        if(sscanf(line, "%s %d %lf %s", info.Model, &info.MemorySpace, &info.ScreenSize, info.Price) == 4)  {
            fwrite(&info, sizeof(PhoneInfo), 1, fout); // ghi 1 bản ghi nhị phân vào file fout
            /* 
            info : con trỏ tới dữ liệu cần ghi
            sizeof(PhoneInfo) : kích thước mỗi phần tử 
            1 : num : số phần tử 
            fout : con trỏ file fout
            */
        }
    }

    fclose(fin);
    fclose(fout);
    printf("Converted %s -> %s succcessfully.\n", input_file, output_file);
}
/*-------------------------------------------------*/
//2. function read all or 1 part of binary file
//Đọc dữ liệu từ file nhị phân vào bộ nhớ
void import_from_DB (const char *input_file) {
    FILE *fin = fopen(input_file, "rb");
    if(!fin) {
        printf("Cannot open file %s!\n", input_file);
        return;
    }
    // đếm số bản ghi trong file
    fseek(fin, 0, SEEK_END); 
    long file_size = ftell(fin); // 
    int total_records = file_size / sizeof(PhoneInfo);
    rewind(fin);

    if(total_records == 0) {
        printf("Database is empty!\n");
        fclose (fin);
        return;
    }

    int mode;
    printf("Choose mode:\n");
    printf("1. Read all records.\n");
    printf("2. Read a part of records.\n");
    printf("Enter choice: ");
    scanf("%d", &mode);

    int start = 0; int end = total_records - 1;
    if(mode == 2) {
        printf("Enter start position (0-%d): ", total_records - 1);
        scanf("%d", &start);
        printf("Enter end position (0-%d): ", total_records - 1);
        scanf("%d", &end);

        if(start < 0) {
            start = 0;
        }
        if(end >= total_records) {
            end = total_records;
        }
        if(start > end ) {
            printf("Invalid range!\n");
            fclose(fin);
            return;
        }
    }
    int num_records = end - start + 1; // 
    // Cấp phát động cho mảng 
    PhoneInfo *arr = (PhoneInfo *)malloc(num_records * sizeof(PhoneInfo));
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fin);
        return;
    }
    // Đọc dữ liệu từ vị trí start -> end
    fseek(fin, start * sizeof(PhoneInfo), SEEK_SET);
    fread(arr, sizeof(PhoneInfo), num_records, fin );
    // in ra màn hình 
    printf("%-20s %-10s %-10s %-10s", "Model", "Memory", "Screen", "Price");
    printf("\n");
    printf("-------------------------------------------------------------\n");
    for(int i = 0; i < num_records ; i ++) {
        printf("%-20s %-10d %-10.1f %-10s\n", arr[i].Model, arr[i].MemorySpace, arr[i].ScreenSize, arr[i].Price);
    }
    printf("-------------------------------------------------------------\n");

    free(arr);
    fclose(fin);

}
/*-------------------------------------------------*/
//3. function print all DB : ok
void print_all_DB(const char *input_file) {
    PhoneInfo info;
    FILE *fin = fopen(input_file, "r");
    if(!fin) {
        printf("Cannot open file %s!", input_file);
        return ;
    }
    printf("All products : \n");
    printf("%-20s %-10s %-10s %-10s\n", "Model", "Memory", "Screen", "Price");
    printf("---------------------------------------------------------------\n");
    char line[MAX_LINE];
    while(fgets(line, sizeof(line), fin)) {
        if(sscanf(line, "%s %d %lf %s", info.Model, &info.MemorySpace, &info.ScreenSize, info.Price) == 4) {
            printf("%-20s %-10d %-10.1f %-10s\n", info.Model, info.MemorySpace, info.ScreenSize, info.Price);
        }
    }
    printf("---------------------------------------------------------------\n");

    fclose(fin);
}
/*-------------------------------------------------*/
//4. Search function (hàm tìm kiếm theo model)
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
    getchar(); // bỏ ký tự '\n' còn sót lại từ scanf
    fgets(search_model, sizeof(search_model), stdin);
    search_model[strcspn(search_model, "\n")] = 0; // xoá \n

    while (fread(&p, sizeof(PhoneInfo), 1, fin) == 1) {
        if(strcmp(search_model, p.Model) == 0) {
            found = 1;
            printf("Your searched product : \n");
            printf("%-20s %-10s %-10s %-10s\n", "Model", "Memory", "Screen", "Price");
            printf("---------------------------------------------------------------\n");
            printf("%-20s %-10d %-10.1f %-15s\n", p.Model, p.MemorySpace, p.ScreenSize, p.Price);
            printf("---------------------------------------------------------------\n");
        }
    }
    if(!found) {
        printf("Product not found! \n");
    }
    fclose(fin);
}
/*-------------------------------------------------*/
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
                import_from_DB(output_file);
                break;
            case 3: 
                print_all_DB(input_file);
                break;
            case 4:
                search_by_model(output_file);
                // tại sao lại là file dat
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

