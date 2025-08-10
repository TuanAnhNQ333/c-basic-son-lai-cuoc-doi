/*
Viết hàm is_in_circle trả về 1 nếu điểm p nằm trong đường tròn c
- kiểm tra hàm bằng chương trình

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct point {
    double x;
    double y;
} point_t;
typedef struct circle {
    point_t center; // tâm đường tròn
    double radius; // bán kính đường tròn
} circle_t;

int is_in_circle(point_t *p, circle_t *c) { // p : con trỏ đến 1 điểm, c : con trỏ đến 1 đường tròn
    double x_distance, y_distance;
    x_distance = p->x - c->center.x;  // khoảng cách p và center theo x
    y_distance = p->y - c->center.y; // khoảng cách p và center theo y
    return (x_distance * x_distance + y_distance * y_distance <= c->radius * c->radius); // x^2 + y^2 <= r^2
    // thoả mãn -> năm trong, còn không thì nằm ngoài
}

int main() {
    point_t p;
    circle_t c;
    printf("Enter the point coordinates\n"); scanf("%lf%lf", &p.x, &p.y); 
    printf("Enter the circle center coordinates\n"); scanf("%lf%lf", &c.center.x, &c.center.y);
    printf("Enter the circle radius\n"); scanf("%lf", &c.radius);
    if(is_in_circle(&p, &c)) {
        printf("The point is inside the circle.\n");
    } else {
        printf("The point is outside the circle.\n");
    }
    return 0;
}
// Dấu . dùng để truy cập thành viên của struct khi bạn có biến struct trực tiếp.
// Dấu -> dùng để truy cập thành viên của struct khi bạn có con trỏ đến struct.
// Ví dụ:
//   point_t p; p.x = 1.0;      // dùng dấu .
//   point_t *pp = &p; pp->x = 2.0; // dùng dấu ->
// Trong hàm is_in_circle, dùng -> vì p và c là con trỏ.
// Trong hàm main, dùng . vì p và c là biến struct.
