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

int is_in_circle(point_t *p, circle_t *c) {
    double x_distance, y_distance;
    x_distance = p->x - c->center.x;
    y_distance = p->y - c->center.y;
    return (x_distance * x_distance + y_distance * y_distance <= c->radius * c->radius);
}

int main() {
    point_t p;
    circle_t c;
    printf("Enter the poin coordinates\n"); scanf("%lf%lf", &p.x, &p.y);
    printf("Enter the circle center coordinates\n"); scanf("%lf%lf", &c.center.x, &c.center.y);
    printf("Enter the circle radius\n"); scanf("%lf", &c.radius);
    if(is_in_circle(&p, &c)) {
        printf("The point is inside the circle.\n");
    } else {
        printf("The point is outside the circle.\n");
    }
    return 0;
}