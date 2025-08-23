/*
Viết chương trình chuyển đổi dữ liệu từ điển Việt Anh từ định dạng văn bản sang nhị
phân.
• Dữ liệu có tại
• http://www.denisowski.org/Vietnamese/vnedict.txt
• Miên Đất Hứa : the Promised Land
• Miến : Burma (short for Miến Điện)
• Miến Điện : Burma
• Miền Trung : Central Vietnam
• Sau đó chương trình đọc dữ liệu từ tập tin nhị phần, hỏi người dùng vị trí bắt đầu và kết thúc của
mục từ và hiển thị các từ nằm ở các vị trí này trong từ điển.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 100
#define MAX_DEF  400
#define MAX_LINE 512

typedef struct {
    char word[MAX_WORD];
    char definition[MAX_DEF];
} DictionaryEntry;

enum {SUCCESS, FAIL};

// Hàm chuyển file văn bản -> file nhị phân
void convert_text_to_binary(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "r");
    if (!fin) {
        printf("Cannot open input file %s\n", input_file);
        return;
    }

    FILE *fout = fopen(output_file, "wb");
    if (!fout) {
        printf("Cannot open output file %s\n", output_file);
        fclose(fin);
        return;
    }

    char line[MAX_LINE];
    DictionaryEntry entry;

    while (fgets(line, sizeof(line), fin)) {
        // Tìm dấu ':' trong dòng
        char *sep = strchr(line, ':');
        if (sep) {
            *sep = '\0'; // tách từ và nghĩa
            strncpy(entry.word, line, MAX_WORD - 1);
            entry.word[MAX_WORD - 1] = '\0'; // tránh tràn chuỗi

            strncpy(entry.definition, sep + 1, MAX_DEF - 1);
            entry.definition[MAX_DEF - 1] = '\0';

            // loại bỏ \n ở cuối definition (nếu có)
            entry.definition[strcspn(entry.definition, "\n")] = '\0';

            fwrite(&entry, sizeof(DictionaryEntry), 1, fout);
        }
    }

    fclose(fin);
    fclose(fout);
    printf("Converted %s -> %s successfully.\n", input_file, output_file);
}

// Hàm hiển thị các từ theo vị trí
void search_and_display(const char *input_file, int start, int end) {
    FILE *fin = fopen(input_file, "rb");
    if (!fin) {
        printf("Cannot open file %s\n", input_file);
        return;
    }

    DictionaryEntry entry;
    int position = 0;

    printf("---- Dictionary Entries (%d to %d) ----\n", start, end);
    while (fread(&entry, sizeof(DictionaryEntry), 1, fin) == 1) {
        if (position >= start && position <= end) {
            printf("%d. %s : %s\n", position, entry.word, entry.definition);
        }
        position++;
    }

    fclose(fin);
}

int main(void) {
    const char *input_file = "vnedict.txt";
    const char *output_file = "vnedict.dat";

    convert_text_to_binary(input_file, output_file);

    int start, end;
    printf("Enter start and end positions: ");
    scanf("%d %d", &start, &end);

    search_and_display(output_file, start, end);

    return SUCCESS;
}
