#include <stdio.h>

#define SIZE 5
int compare_arrays(int arr1[], int arr2[], int size) {
    int i = 0;
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Mảng khác nhau
        }
    }
    return 1; // Mảng giống nhau

}
int main(void) {
    int input1[SIZE], input2[SIZE];
    printf("Enter a list of %d integers\n", SIZE);
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &input1[i]);
    }
    printf("Enter a list of %d integers\n", SIZE);
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &input2[i]);
    }

   if (compare_arrays(input1, input2, SIZE)) {
       printf("Hai mảng giống nhau.\n");
   } else {
       printf("Hai mảng khác nhau.\n");
   }

   return 0;
}
