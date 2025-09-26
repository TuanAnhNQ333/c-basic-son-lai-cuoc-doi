#include <stdio.h>
#include <string.h>   // để dùng memcpy

// Hàm hoán đổi 2 phần tử bất kỳ trong mảng
void swapElements(void *elementA, void *elementB, size_t sizeOfElement) {
    char temp[sizeOfElement];
    memcpy(temp, elementA, sizeOfElement);
    memcpy(elementA, elementB, sizeOfElement);
    memcpy(elementB, temp, sizeOfElement);
}

// Hàm partition cho quicksort
int partitionArray(void *array, int leftIndex, int rightIndex, size_t sizeOfElement, 
                   int (*compareFunction)(const void *, const void *)) {
    char *charArray = (char *)array;
    void *pivotElement = charArray + rightIndex * sizeOfElement;  // chọn pivot là phần tử cuối
    int storeIndex = leftIndex - 1;

    for (int currentIndex = leftIndex; currentIndex < rightIndex; currentIndex++) {
        void *currentElement = charArray + currentIndex * sizeOfElement;
        if (compareFunction(currentElement, pivotElement) < 0) { // nếu nhỏ hơn pivot
            storeIndex++;
            swapElements(charArray + storeIndex * sizeOfElement, currentElement, sizeOfElement);
        }
    }
    swapElements(charArray + (storeIndex + 1) * sizeOfElement, pivotElement, sizeOfElement);
    return storeIndex + 1;
}

// Hàm quicksort tổng quát (tự cài đặt)
void quickSortGeneral(void *array, int leftIndex, int rightIndex, size_t sizeOfElement,
                      int (*compareFunction)(const void *, const void *)) {
    if (leftIndex < rightIndex) {
        int pivotIndex = partitionArray(array, leftIndex, rightIndex, sizeOfElement, compareFunction);

        quickSortGeneral(array, leftIndex, pivotIndex - 1, sizeOfElement, compareFunction);
        quickSortGeneral(array, pivotIndex + 1, rightIndex, sizeOfElement, compareFunction);
    }
}

// Hàm my_qsort: giao diện giống qsort chuẩn
void my_qsort(void *array, size_t numberOfElements, size_t sizeOfElement,
              int (*compareFunction)(const void *, const void *)) {
    if (numberOfElements > 0) {
        quickSortGeneral(array, 0, (int)numberOfElements - 1, sizeOfElement, compareFunction);
    }
}

// ================== Ví dụ sử dụng ==================

// Hàm so sánh số nguyên
int compareIntegers(const void *a, const void *b) {
    int valueA = *(const int *)a;
    int valueB = *(const int *)b;
    return valueA - valueB;
}

// Hàm so sánh chuỗi
int compareStrings(const void *a, const void *b) {
    const char *stringA = *(const char **)a;
    const char *stringB = *(const char **)b;
    return strcmp(stringA, stringB);
}

int main() {
    // Ví dụ 1: sắp xếp mảng số nguyên
    int numbers[] = {42, 7, 19, 3, 25};
    int sizeNumbers = sizeof(numbers) / sizeof(numbers[0]);

    my_qsort(numbers, sizeNumbers, sizeof(int), compareIntegers);

    printf("Mang so nguyen sau khi sap xep: ");
    for (int i = 0; i < sizeNumbers; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Ví dụ 2: sắp xếp mảng chuỗi
    const char *names[] = {"Tuan", "Anh", "Minh", "Hoa"};
    int sizeNames = sizeof(names) / sizeof(names[0]);

    my_qsort(names, sizeNames, sizeof(char *), compareStrings);

    printf("Mang chuoi sau khi sap xep: ");
    for (int i = 0; i < sizeNames; i++) {
        printf("%s ", names[i]);
    }
    printf("\n");

    return 0;
}
