/*
Viết chương trình nhập vào một xâu ký tự và hiển thị số lần xuất hiện của mỗi ký tự có trong xâu. 

Kết quả hiển thị với xâu đầu vào:  "hello, world!"

The letter 'd' appears 1 time(s).
The letter 'e' appears 1 time(s).
The letter 'h' appears 1 time(s).
The letter 'l' appears 3 time(s).
The letter 'o' appears 2 time(s).
The letter 'r' appears 1 time(s).
The letter 'w' appears 1 time(s).

Lưu ý: Chỉ xét các ký tự chữ cái thường trong xâu, các ký tự khác bỏ qua!
*/
#include <stdio.h>
#include <string.h>

char str[10000000] = {0};
int count[256] = {0};
int main() {

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Loại bỏ ký tự newline

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            count[str[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
        }
    }

    return 0;
}