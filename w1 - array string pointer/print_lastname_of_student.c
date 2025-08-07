#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_LEN 100

void print_lastname_of_student(char students[MAX_STUDENTS][MAX_LEN], int n) {
    for (int i = n - 1; i >= 0; i--) {
        char *last_name = strrchr(students[i], ' ');
        if (last_name != NULL) {
            printf("%s\n", last_name + 1); // In ra họ
        } else {
            printf("No last name found for student %d\n", i + 1);
        }
    }
}
int main() {
    int n;
    char students[MAX_STUDENTS][MAX_LEN];

    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar(); // Đọc ký tự newline còn lại sau scanf

    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i + 1);
        fgets(students[i], MAX_LEN, stdin);
        students[i][strcspn(students[i], "\n")] = '\0'; // Loại bỏ ký tự newline
    }

    printf("Last names of students in reverse order:\n");
    print_lastname_of_student(students, n);

    return 0;
}