/*
- struct
- quicksort
- compare
- input : scanf
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STRING_LENGTH 21
typedef struct {
    int ID;
    char email[STRING_LENGTH];
} student;
// ham quick sort
void swap (student *a, student *b) {
    student temp = *a;
    *a = *b;
    *b = temp;
}
int partition (student arr[], int low, int high) {
    student pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j ++) {
        if(strcmp(arr[j].email, pivot.email) <= 0) {
            i ++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quicksort(student arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        // sap xep phan tu
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    student students[n];
    for(int i = 0; i < n; i ++) {
        scanf("%d %s", &students[i].ID, students[i].email);
    }
// quick sort recall
    quicksort(students, 0, n - 1);
    for(int i = 0; i < n; i ++) {
        printf("%d %s\n", students[i].ID, students[i].email);
    }
    return 0;
}