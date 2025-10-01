#include <stdio.h>

// Hoán đổi 2 số nguyên
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Hàm chia mảng (partition)
int partition(int arr[], int left, int right) {
    int pivot = arr[right];   // chọn pivot là phần tử cuối
    int i = left - 1;         // vị trí cho phần tử nhỏ hơn pivot

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) { // nếu nhỏ hơn pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]); // đưa pivot về đúng chỗ
    return i + 1;
}

// Hàm quick sort đệ quy
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);

        quickSort(arr, left, pivotIndex - 1);   // sắp xếp bên trái pivot
        quickSort(arr, pivotIndex + 1, right); // sắp xếp bên phải pivot
    }
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
