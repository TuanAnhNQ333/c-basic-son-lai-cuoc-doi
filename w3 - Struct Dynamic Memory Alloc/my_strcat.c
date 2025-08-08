/*
Cài đặt hàm my_strcat
- Đầu vào : 2 xâu ký tự s1, s2
- đầu ra : 1 con trỏ trỏ tới vùng nhớ động chứa nội dung là xâu kết quả của phép nối 2 xâu s1 và s2
- ví dụ : nối "hello_" và "wordl!" trả về "hello_world!"
+ sử dụng kỹ thuật cấp phát bộ nhớ động
+ kiểm tra lại các hàm đã viết

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

char *my_strcat(char *str1, char *str2) {
    int len1, len2;
    char *result;
    len1 = strlen(str1);
    len2 = strlen(str2);
    result = (char*)malloc((len1 + len2 + 1) *sizeof(char));
    if(result == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(result, str1);
    strcpy(result + len1, str2);
    return result;
}
int main() {
    char str1[MAX_LEN + 1], str2[MAX_LEN + 1];
    char *cat_str;
    printf("Enter two strings:\n");
    scanf("%100s", str1);
    scanf("%100s", str2);
    cat_str = my_strcat(str1, str2);
    if(cat_str == NULL) {
        printf("Problem allocating memory!\n");
        return 1 ;
    } 
    printf("the concatenation of %s and %s is %s\n", str1, str2, cat_str);
    free(cat_str);
    return 0;
}