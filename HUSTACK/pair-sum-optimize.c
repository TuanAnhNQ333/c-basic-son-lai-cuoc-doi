/*
PAIR SUM
• Description:
  Given a sequence of positive integer numbers a1...an and a query integer x,
  calculate the number of pairs (ai, aj) where ai + aj <= x.
• Input:
  - Line 1: Contains n (number of elements)
  - Line 2: Contains n positive integers a1...an
  - Line 3: Contains q (number of queries)
  - Next q lines: Each contains a query integer x
• Output:
  - q lines, each containing the number of pairs satisfying the corresponding query
• Example:
  Input:
    5
    5 10 2 7 9
    2
    15
    13
  Output:
    7
    5
*/
#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh để dùng trong qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Đếm số cặp có tổng <= x
long long count_pairs(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    long long count = 0;

    while (left < right) {
        if (arr[left] + arr[right] <= x) {
            // Nếu arr[left] + arr[right] <= x
            // thì tất cả cặp (arr[left], arr[left+1..right]) đều hợp lệ
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bước 1: Sắp xếp mảng
    qsort(arr, n, sizeof(int), cmp);

    int q;
    scanf("%d", &q);

    // Xử lý từng query
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", count_pairs(arr, n, x));
    }

    return 0;
}

