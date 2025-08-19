/*
 Write a program to read a specific range of records from the phonebook.dat file.
 For example, read records from the 2nd to the 3rd, or from the 3rd to the 6th.
 Then, modify the email field of these records and write them back to the file at the correct position.
 The program should dynamically allocate memory to store exactly the number of records read from the file.
 For example, allocate a dynamic array with 4 elements to store records from the 3rd to the 6th.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {SUCCESS, FAIL} ;
#define MAX_ELEMENT 20
// phone book structure
typedef struct phoneaddress {
    char name[20];
    char telephone[11];
    char email[25];
} phoneaddress;
int main(void) {
    FILE *fp;
    phoneaddress *phonearr;

    int i, n, irc;
    int reval = SUCCESS;
    printf("Read from 2nd data to 3rd data\n");
    if((fp = fopen("phonebook.dat", "r+b")) == NULL) {
        printf("Cannot open file %s.\n", "phonebook.dat");
        reval = FAIL;
    } 
    // memory allocation
    phonearr = (phoneaddress*)malloc(MAX_ELEMENT * sizeof(phoneaddress));
    if(phonearr == NULL) {
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    if(fseek(fp, 1 * sizeof(phoneaddress), SEEK_SET) != 0) {
        printf("Seek failed!\n");
        return FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), 2, fp);
    for(i = 0; i < 2; i ++) {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].telephone);
        printf("%s\n", phonearr[i].email);
    }
    // modifying some data
    strcpy(phonearr[1].name, "Lan Hoa");
    strcpy(phonearr[1].telephone, "0987654321");
    strcpy(phonearr[1].email, "lanhoa@example.com");
    // write back to file
    fseek(fp, 1 * sizeof(phoneaddress), SEEK_SET);
    irc = fwrite(phonearr, sizeof(phoneaddress), 2, fp);
    printf("fwrite return code = %d\n", irc);
    fclose(fp);
    free(phonearr); // free allocated memory
    return reval;
}