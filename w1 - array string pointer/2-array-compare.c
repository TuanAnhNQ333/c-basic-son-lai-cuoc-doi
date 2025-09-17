/*
Viết chương trình dạng hàm:

1. So sánh 2 mảng có cùng số lượng phần tử:
   • Kiểm tra các phần tử ở cùng vị trí có giống nhau không
   • Trả về 1 nếu trùng nhau, 0 nếu ngược lại

2. Kiểm tra 2 mảng có cùng phần tử (mở rộng):
   • Hai mảng chứa các phần tử giống nhau
   • Các phần tử không cần ở cùng vị trí
   • Ví dụ: 
     - A={2,4,4,5} trùng với B={4,5,4,2}
     - A={2,4,4,5} không trùng với C={5,5,4,2}

3. Kiểm tra thứ tự tương đối giữa 2 mảng:
   • So sánh quan hệ giữa các phần tử liên tiếp
   • Nếu A[i]<=A[i+1] thì B[i]<=B[i+1]
   • Ví dụ:
     A={1,3,2,7} cùng thứ tự với B={2,7,3,4}
*/
#include<stdio.h>
#include<stdlib.h>
void sort(int array[], int n) {
    for(int i = 0; i < n - 1; i ++) {
        for(int j = i + 1; j < n; j ++) {
            if(array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
int IdenticalArray(int array1[], int array2[], int n) {
    for(int i = 0; i < n; i ++) {
        if(array1[i] != array2[i]) {
            return 0;
        }
    }
    return 1;
}
int IsSameElements(int array1[], int array2[], int n) {
    sort(array1, n);
    sort(array2, n);
    for(int i = 0; i < n; i ++) {
        if(array1[i] != array2[i]) {
            return 0;
        }
    }
    return 1;
}
int IsSameOrder(int array1[], int array2[], int n) {
    for(int i = 0; i < n - 1; i ++) {
        int relationA = (array1[i] <= array1[i + 1]);
        int relationB = (array2[i] <= array2[i + 1]);
        if(relationA != relationB) {
            return 0;
        }
    }
    return 1;
}
int main(void) {
    int n; int choice;
    printf("Nhap so phan tu n : \n");
    scanf("%d", &n);

    int array1[n], array2[n];
    printf("Nhap mang array1 : ");
    for(int i = 0; i < n; i ++) {
        scanf("%d", &array1[i]);
    }
    printf("Nhap mang array2 : ");
    for(int i = 0; i < n; i ++) {
        scanf("%d", &array2[i]);
    }

    do {
        printf("\n======= MENU =======\n");
        printf("1. Kiem tra 2 mang giong nhau tung vi tri \n");
        printf("2. Kiem tra 2 mang co cung phan tu\n");
        printf("3. Kiem tra thu tu tuong doi giua hai mang\n");
        printf("0. thoat\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 : 
                if(IdenticalArray(array1, array2, n)) {
                    printf("hai mang giong het nhau\n");
                } else {
                    printf("hai mang khong giong het nhau\n");
                }
                break;
            case 2 : 
                if(IsSameElements(array1, array2, n)) {
                    printf("hai mang co cung phan tu\n");
                } else {
                    printf("hai mang khong cung phan tu\n");
                }
                break;
            case 3: 
                 if(IsSameOrder(array1, array2, n)) {
                    printf("hai mang co cung thu tu lien tiep\n");
                } else {
                    printf("hai mang khong cung thu tu lien tiep\n");
                }
                break;
            case 0 : 
                printf("Thoat chuong trinh\n");
                break;
            default : 
                printf("Lua chon khong hop le !\n");
        }
    } while (choice != 0);

    return 0;

}