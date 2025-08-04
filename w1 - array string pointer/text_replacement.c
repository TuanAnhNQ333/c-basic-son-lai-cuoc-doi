#include<stdio.h>
#include<string.h>

#define MAX_LEN 1001
#define MAX_RESULT 10000

// Hàm loại bỏ ký tự xuống dòng ở cuối chuỗi
// Nếu ký tự cuối là '\n', thay thế nó bằng ký tự kết thúc chuỗi
// Điều này giúp tránh lỗi khi xử lý chuỗi trong các hàm khác
// Hàm này không trả về giá trị gì, nó sửa đổi chuỗi str trực tiếp
void remove_newline(char str[]) {
    int len = strlen(str); // do dai chuoi str 
    if(len > 0 && str[len - 1] == '\n') { // kien tra ky tu cuoi cua str
        // neu ky tu cuoi la \n thi thay the bang ky tu ket thuc chuoi '\0'
        // len - 1 la vi tri cuoi cung cua chuoi
        str[len - 1] = '\0';
    }
}
// Hàm kiểm tra xem chuỗi T có chứa chuỗi P1 tại vị trí pos hay không
// Nếu có, hàm trả về 1 (true), nếu không thì trả về
int is_match (char T[], char P1[], int pos, int lenP1) {
    for (int j = 0; j < lenP1; j ++) { // Duyệt qua từng ký tự của P1
        // Kiểm tra xem ký tự tại vị trí pos + j trong T có bằng ký
        if(T[pos + j] != P1[j]) { // Nếu không khớp
            return 0;
        }
    }
    return 1; 
}
int main () {
    char P1[MAX_LEN], P2[MAX_LEN], T[MAX_LEN];
    char result[MAX_RESULT];
    int i = 0, k = 0; 

    fgets(P1, MAX_LEN, stdin);
    fgets(P2, MAX_LEN, stdin);
    fgets(T, MAX_LEN, stdin);
    
    remove_newline(P1); // Loại bỏ ký tự xuống dòng ở cuối P1
    remove_newline(P2); // Loại bỏ ký tự xuống dòng ở cuối P2
    remove_newline(T);  // Loại bỏ ký tự xuống dòng ở cuối T

    int lenP1 = strlen(P1);
    int lenT = strlen(T);
    // Duyệt qua từng ký tự trong chuỗi T
    while (i < lenT) {
        // Kiểm tra xem có khớp với P1 tại vị trí i không
        if(i + lenP1 <= lenT && is_match(T, P1, i, lenP1)) {
            // Nếu có khớp, ghi P2 vào kết quả
            for(int j = 0; P2[j] != '\0'; j ++) {
                result[k ++] = P2[j];
            }
            i += lenP1; // Bỏ qua đoạn P1
        } else {
            // Nếu không khớp, ghi ký tự T[i] vào kết quả
            result[k ++] = T[i ++];
        }
    }
    result[k] = '\0'; // Kết thúc chuỗi kết quả
    printf("%s\n", result);
    return 0;
}


/*
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001
#define MAX_RESULT 10000

void remove_newline(char str[]) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int is_match(char T[], char P1[], int pos, int lenP1) {
    for (int j = 0; j < lenP1; j++) {
        if (T[pos + j] != P1[j]) {
            return 0; // không khớp
        }
    }
    return 1; // khớp
}

int main() {
    char P1[MAX_LEN], P2[MAX_LEN], T[MAX_LEN];
    char result[MAX_RESULT];
    int i = 0, k = 0;

    fgets(P1, MAX_LEN, stdin);
    fgets(P2, MAX_LEN, stdin);
    fgets(T, MAX_LEN, stdin);

    remove_newline(P1);
    remove_newline(P2);
    remove_newline(T);

    int lenP1 = strlen(P1);
    int lenT = strlen(T);

    while (i < lenT) {
        if (i + lenP1 <= lenT && is_match(T, P1, i, lenP1)) {
            // Ghi P2 vào result
            for (int j = 0; P2[j] != '\0'; j++) {
                result[k++] = P2[j];
            }
            i += lenP1; // Bỏ qua đoạn P1
        } else {
            result[k++] = T[i++];
        }
    }

    result[k] = '\0'; // Kết thúc chuỗi

    printf("%s\n", result);

    return 0;
}
*/