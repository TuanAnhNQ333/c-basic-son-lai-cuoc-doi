#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    char *str;
    str = (char *)malloc(15);
    strcpy(str, "tutorialspoint");
    printf("String = %s, Address = %s\n", str, str);
    // cấp phát lại bộ nhớ
    str = (char *)realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s, Address = %s\n", str, str);
    // giải phóng bộ nhớ
    free(str);
    return 0;
}