/*
Viết hàm kiểm tra xem hai hình tròn có giao nhau hay không. Viết một chương
trình cho phép tạo ra một mảng động các phần tử là các hình tròn, số lượng phần tử do
người dùng cung cấp tại thời điểm chạy chương trình.
 Người dùng có thể lựa chọn:
• Nhập thủ công thông tin cho mỗi hình tròn
• Tự động sinh thông tin ngẫu nhiên cho mỗi hình tròn.
 Chương trình sử dụng hàm nói trên và hiển thị:
• Thông tin về các hình tròn
• Thông tin về hình tròn giao với nhiều hình tròn khác nhất (cùng với thông tin chi tiết,
ví dụ giao với các hình tròn nào..)
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct point {
    double x;
    double y;
} point_t;

typedef struct circle {
    point_t center; 
    double radius;
} circle_t;

int intersect_circle(circle_t *c1, circle_t *c2) {
    double distance;
    double radius_sum;
    double radius_diff;

    // khoảng cách giữa 2 tâm 
    distance = sqrt(pow(c2->center.x - c1->center.x, 2) + pow(c2->center.y - c1->center.y, 2)); 
    // tổng bán kinh : 
    radius_sum = c1->radius + c2->radius;
    radius_diff = fabs(c1->radius - c2->radius);
    return (distance <= radius_sum && distance >= radius_diff);
}
// hàm sinh ngẫu nhiên 
double rand_double (double min, double max) {
    return min + (rand() / (double)RAND_MAX) * (max - min) ;
}
int main() {
    int n, i, j, choice;
    int max_intersections = 0;
    int *intersections_counts;
    // mảng động chứa các hình tròn
    circle_t *circles;

    srand(time(NULL));

    printf("Enter the number of circles: ");
    scanf("%d", &n);
    // cấp phát bộ nhớ cho mảng động các hình tròn
    circles = malloc(n * sizeof(circle_t));
    intersections_counts = calloc(n, sizeof(int));
    if(circles == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Choose input method:\n");
    printf("1. Manual input\n");
    printf("2. Random generation\n");
    scanf("%d", &choice);
    // nhập thông tin cho từng hình tròn
    if(choice == 1) {
        for(i = 0; i < n; i ++) {
            printf("Enter the center coordinates (x y) and radius for circle %d: ", i + 1);
            scanf("%lf %lf %lf", &circles[i].center.x, &circles[i].center.y, &circles[i].radius);
        }
    } else if(choice == 2) {
        for(i = 0; i < n; i ++) {
            circles[i].center.x = rand_double(-10, 10);
            circles[i].center.y = rand_double(-10, 10);
            circles[i].radius = rand_double(1, 5);
        }
    }
    // in thông tin các hình tròn
    printf("\n");
    printf("List of circles:\n");
    for(i = 0; i < n; i ++) {
        printf("Circle %d: Center(%.2f, %.2f), Radius %.2f\n", i + 1, circles[i].center.x, circles[i].center.y, circles[i].radius);
    }
    // kiểm tra giao nhau giữa các hình tròn
    for(i = 0; i < n; i ++) {
        intersections_counts[i] = 0; // đếm số hình tròn giao với hình tròn i
        for(j = i + 1; j < n; j ++) {
            if(i != j && intersect_circle(&circles[i], &circles[j])) {
                printf("Circle %d intersects with Circle %d\n", i + 1, j + 1);
                intersections_counts[i]++;
                intersections_counts[j]++;
            }
        }
    }
    // thông tin về hình tròn giao với nhiều hình tròn khác nhất
    for(i = 0; i < n; i++) {
        if(intersections_counts[i] > max_intersections) {
            max_intersections = intersections_counts[i];
                }
    }
    // in thông tin hình tròn có nhiều giao nhau nhất
    printf("\n");
    printf("Circles with most intersections (%d):\n", max_intersections);
    for(i = 0; i < n; i ++) {
        if(intersections_counts[i] == max_intersections) {
            printf("Circle %d: Center(%.2f, %.2f), Radius %.2f\n", i + 1, circles[i].center.x, circles[i].center.y, circles[i].radius);
            printf("  Intersects with: ");
            for(j = 0; j < n; j ++) {
                if(i != j && intersect_circle(&circles[i], &circles[j])) {
                    printf("%d ", j + 1);
                }
            }
            printf("\n");
        }
    }
    free(circles);
    free(intersections_counts);
    return 0;
}
