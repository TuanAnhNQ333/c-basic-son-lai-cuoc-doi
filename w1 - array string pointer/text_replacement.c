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
