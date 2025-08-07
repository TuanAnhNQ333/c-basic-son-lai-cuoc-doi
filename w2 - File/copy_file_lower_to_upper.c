#include<stdio.h>
#include<ctype.h>


enum{SUCCESS, FAIL};
void CharReadWrite(FILE *fin, FILE *fout) {
    int c;
    while((c = fgetc(fin)) != EOF) {
        if (islower(c)) {
            c = toupper(c);
        }
        else if(isupper(c)) {
            c = tolower(c);
        }
        fputc(c, fout);
        putchar(c);
    }
}
int main(void) {
    FILE *fptr1, *fptr2;
    char filename1[] = "note.txt";
    char filename2[] = "upper.txt";
    int reval = SUCCESS;
    if ((fptr1 = fopen(filename1, "r")) == NULL) {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    } else if ((fptr2 = fopen(filename2, "w")) == NULL) {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    } else {
        CharReadWrite(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}