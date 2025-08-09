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
/* giải thích về -> và .
Dấu -> được sử dụng để truy cập thành viên của struct thông qua con trỏ.
   Ví dụ: p->x có nghĩa là truy cập thành viên x của struct point_t mà p trỏ đến.
   Tương tự, c->center.x có nghĩa là truy cập thành viên x của struct point_t mà c->center trỏ đến.
Dấu . được sử dụng để truy cập thành viên của struct thông qua biến struct.
    Ví dụ: p.x có nghĩa là truy cập thành viên x của struct point_t p.
    Tương tự, c.center.x có nghĩa là truy cập thành viên x của struct point_t mà c.center trỏ đến.
    Sự khác biệt chính là dấu -> được sử dụng khi bạn có một con trỏ đến struct,
         trong khi dấu . được sử dụng khi bạn có một biến struct trực tiếp.
    
*/