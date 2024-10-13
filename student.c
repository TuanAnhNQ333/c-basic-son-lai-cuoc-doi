#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct
{
    float x;      // Hoành độ tâm
    float y;      // Tung độ tâm
    float radius; // Bán kính
} Circle;
int check(Circle c1, Circle c2)
{
    float distance = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    return distance <= (c1.radius + c2.radius);
}
Circle inputCircle()
{
    Circle c;
    printf("Nhap tam (x y) va bien do: ");
    scanf("%f %f %f", &c.x, &c.y, &c.radius);
    return c;
}
Circle randomCircle()
{
    Circle c;
    c.x = (float)(rand() % 300);
    c.y = (float)(rand() % 300);
    c.radius = (float)(rand() % 50 + 1);
    return c;
}
void printCircle(Circle c)
{
    printf("Tam(%.2f, %.2f), Bien do: %.2f\n", c.x, c.y, c.radius);
}
int main()
{
    int n, choice;
    printf("So luong hinh tron: ");
    scanf("%d", &n);
    Circle* circles = (Circle*)malloc(n * sizeof(Circle));
    if (circles == NULL)
    {
        fprintf(stderr, "fasle\n");
        return 1;
    }
    printf("Che do:\n1. Nhap thu cong\n2. Ngau nhien\n");
    scanf("%d", &choice);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        if (choice == 1)
        {
            circles[i] = inputCircle();
        }
        else
        {
            circles[i] = randomCircle();
        }
    }
    int a[10000]= {0};
    int max=0;
    printf("\nDanh sach:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Circle %d, ",i+1);
        printCircle(circles[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (check(circles[i], circles[j]))
            {
                printf("Circle %d va Circle %d giao nhau .\n", i + 1, j + 1);
            }
            else
            {
                printf("Circle %d va Circle %d khong giao nhau .\n", i + 1, j + 1);
            }
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (check(circles[i], circles[j]))
            {
                a[i]++;
                a[j]++;
            }
        }
    }
    int h=0;
    for(int i=0; i<n; i++)if(max<a[i])max=a[i];
    printf("Duong tron giao nhieu nhat: \n");
    for(int i=0; i<n; i++)
        if(a[i]==max&&max!=0)
        {
            printf("Circle %d, ",i+1);
            printCircle(circles[i]);
 
        }
        else h++;
    if(h!=0&&max==0) printf("Khong co\n");
    free(circles);
    return 0;
}