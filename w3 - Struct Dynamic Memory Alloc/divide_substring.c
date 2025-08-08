/*
Xây dựng hàm với : char * subStr(char* s1, int offset, int number)
- Hàm tách xâu con từ xâu s1 bắt đầu từ ký tự tại chỉ số offset(tính từ 0) và có độ dài là number ký tự
- chú ý kiểm tra tính hợp lệ của các đối số. trong trường hợp giá trị number lớn hơn độ dài phần còn lại của xâu s1 tính từ vị trí offset
----> trả về xâu con là phần còn lại của s1 tính từ vị trí offset
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * subStr(char *s1, int offset, int number) {
    int len = strlen(s1);
    if(offset <0 || offset >= len || number < 0) {
        printf("Invalid offset or number.\n");
        return NULL;
    }
    if(offset + number > len) {
        number = len - offset; 
        printf("Number exceeds remaining length, adjusting to %d.\n", number);
    }
    char *sub = (char *)malloc((number + 1) *sizeof(char));
    if(sub == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strncpy(sub, s1 + offset, number);
    sub[number] = '\0'; // null terminate the substring
    return sub;
}
int main() {
    char str[100];
    int offset, number;
    printf("Enter a string: \n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // remove newline character
    printf("Enter offset and number of characters to extract: \n");
    scanf("%d %d", &offset, &number);
    char *result = subStr(str, offset, number);
    if(result != NULL) {
        printf("Substring: %s\n", result);
        free(result);
    } else {
        printf("Failed to extract substring.\n");
    }

    return 0;
}