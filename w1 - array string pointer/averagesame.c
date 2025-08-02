#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    float average = (float)sum / n;
    printf("Average: %.2f\n", average);

    // Tìm giá trị chênh lệch nhỏ nhất
    float mindiff = fabs(arr[0] - average);
    for (int i = 1; i < n; i++) {
        float diff = fabs(arr[i] - average);
        if (diff < mindiff) {
            mindiff = diff;
        }
    }

    // In ra các phần tử có giá trị gần nhất với average
    printf("Element(s) closest to the average:\n");
    for (int i = 0; i < n; i++) {
        float diff = fabs(arr[i] - average);
        // Chấp nhận sai số nhỏ do làm tròn
        if (fabs(diff - mindiff) < 1e-6) {
            printf("%d at index %d\n", arr[i], i);
        }
    }

    return 0;
}