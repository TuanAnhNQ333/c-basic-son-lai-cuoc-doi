/*
Viết chương trình sao chép tập tin theo nhiều chế độ, hoạt động với giao diện
menu dòng lệnh với các chức năng chính như sau:
1. Copy by character
2. Copy by line
3. Copy by block - optional size
4. Quit
• Ở mỗi chức năng sao chép, sau khi hoàn thành việc sao chép, hiển thị thời gian thực hiện
theo đơn vị mili giây để so sánh.
Chú ý: Tập tin nguồn phải là tập tin văn bản có kích thước tối thiểu là 640KB.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LEN 1024
enum {SUCCESS, FAIL};

void CharReadWrite(FILE *fin, FILE *fout) {
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
    }
}
void LineReadWrite(FILE *fin, FILE *fout) {
    char buffer[MAX_LEN + 1];
    while(fgets(buffer, MAX_LEN, fin) != NULL) {
        fputs(buffer, fout);
    }
}
void BlockReadWrite(FILE *fin, FILE *fout, int block_size) {
    int num;
    char *buffer = malloc(block_size);
    if(buffer == NULL) {
        printf("Memory allocation failed!\n");
        return ;
    }
    while ((num = fread(buffer, sizeof(char), block_size, fin)) > 0) {
        fwrite(buffer, sizeof(char), num, fout);
    }
    free(buffer);
}
int main(void) {
    FILE *fptr1, *fptr2;
    char filename1[] = "student.txt";
    char filename2[] = "student_copy.txt";

    int choice, block_size;
    int reval = SUCCESS;
    
    if((fptr1 = fopen(filename1, "r"))== NULL) {
        printf("Cannot open file %s.\n", filename1);
        reval = FAIL;
    } else {
        do {
            printf("Choose copy method: \n");
            printf("1. Copy by character\n");
            printf("2. Copy by line\n");
            printf("3. Copy by block\n");
            printf("4. Quit\n");
            printf("Enter your choice: ");

            if(scanf("%d", &choice) != 1) {
                printf("Invalid input!");
                while(getchar() != '\n');
                continue;
            }
            
            if(choice == 4) {
                printf("Exiting program.\n");
                break;
            }
            FILE *fptr2 = fopen(filename2, "w");
            if(!fptr2) {
                printf("Cannot open file %s for writing.\n", filename2);
                fclose(fptr1);
                return FAIL;
            }

            fseek(fptr1, 0, SEEK_SET);

            clock_t start = clock();

            switch (choice) {
                case 1: 
                    CharReadWrite(fptr1, fptr2);
                    printf("\n");
                    break;
                case 2:
                    LineReadWrite(fptr1, fptr2);
                    printf("\n");
                    break;
                case 3: 
                    printf("Enter block size (1 to %d): ", MAX_LEN);
                    if(scanf("%d", &block_size) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n');
                    } else if(block_size <= 0 || block_size > MAX_LEN) {
                        printf("Invalid block size! Please enter a value between 1 and %d.\n", MAX_LEN);
                    } else{
                        BlockReadWrite(fptr1, fptr2, block_size);
                    }
                    break;
                default: 
                    printf("Invalid choice! Please try again.\n");
            }
            clock_t end = clock();
            double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            printf("\nTime taken: %.3f ms\n", time_taken);

            fclose(fptr2);

        } while (choice != 4);
        fclose(fptr1);
        printf("File copy completed successfully.\n");
    }
    return reval;
}