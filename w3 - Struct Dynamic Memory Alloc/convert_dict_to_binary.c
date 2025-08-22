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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_WORD_LENGTH 500
enum {SUCCESS, FAIL};
typedef struct DictionaryEntry {
    char word[MAX_WORD_LENGTH];
    char definition[MAX_WORD_LENGTH];
} DictionaryEntry;
void convert_text_to_binary(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "wb");
    if (!fin || !fout) {
        printf("Cannot open file.\n");
        return;
    }

    DictionaryEntry entry;
    while (fscanf(fin, "%s %[^\n]", entry.word, entry.definition) == 2) {
        fwrite(&entry, sizeof(DictionaryEntry), 1, fout);
    }

    fclose(fin);
    fclose(fout);
    printf("Converted %s to %s successfully.\n", input_file, output_file);
}

void search_and_display(const char *input_file, int start, int end) {
    FILE *fin = fopen(input_file, "rb");
    if (!fin) {
        printf("Cannot open file %s.\n", input_file);
        return;
    }

    DictionaryEntry entry;
    int position = 0;
    printf("---- Dictionary Entries ----\n");
    while (fread(&entry, sizeof(DictionaryEntry), 1, fin) == 1) {
        if (position >= start && position <= end) {
            printf("Word: %s, Definition: %s\n", entry.word, entry.definition);
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

    return 0;
}