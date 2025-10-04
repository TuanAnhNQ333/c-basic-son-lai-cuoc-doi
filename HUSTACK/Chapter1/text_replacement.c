/*
Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). Hãy thay thế các xâu P1 trong T bằng xâu P2.
Dữ liệu
· Dòng 1: xâu P1
· Dòng 2: xâu P2
· Dòng 3: văn bản T
Kết quả:
· Ghi văn bản T sau khi thay thế
Ví dụ
Dữ liệu
AI
Artificial Intelligence
Recently, AI is a key technology. AI enable efficient operations in many fields.
Kết quả
Recently, Artificial Intelligence is a key technology. Artificial Intelligence enable efficient operations in many fields.
*/
#include<stdio.h>
#include<string.h>
#define maxlen 1000
void text_replace(char *replace, char *replace_done, char *input) {
    char output[maxlen] = "";
    int i = 0;
    int pos = 0;

    while(input[i] != '\0') {
        int j = 0;
        int match = 1;
        while(replace[j] != '\0') {
            if(input[i + j] != replace[j]) {
                match = 0;
                break;
            }
            j ++;
        }
        if(match) {
            for(int k = 0; replace_done[k] != '\0'; k ++) {
                output[pos++] = replace_done[k];
            }
            i += j;
        } else {
            output[pos++] = input[i++];
        }
    }
    output[pos] = '\0';
    strcpy(input, output);
}
int main(void) {
    char a[maxlen];
    char b[maxlen];

    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);

    char string[maxlen];
    fgets(string, sizeof(string), stdin);

    a[strcspn(a, "\n")] = '\0';
    b[strcspn(b, "\n")] = '\0';
    string[strcspn(string, "\n")] = '\0';

    text_replace(a, b, string);
    printf("%s", string);
    return 0;

}