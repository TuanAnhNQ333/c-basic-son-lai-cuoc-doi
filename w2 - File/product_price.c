/*
Tạo một tập tin văn bản có tên product.txt, mỗi dòng trong đó chứa thông tin về một sản phẩm: ID
(kiểu int), Product Name (xâu ký tự không chứa ký tự trắng), Price (kiểu double). Các trường dữ liệu trên
phân tách với nhau bởi một ký tự space hoặc tab. Ví dụ
• 1 Samsung_Television_4K 20000000
• 2 Apple_MacBook_2020 18560000
• Viết chương trình đọc tập tin trên vào một mảng các phần tử cấu trúc và sau đó hiện nội dung mảng trên ra
màn hình dưới dạng:
• No Product Name Price
• 1 Samsung_Television_4K 20000000
•
…
• Gợi ý
• Khi đọc số thực double dùng fscanf với xâu định dạng “%lf”
• Trong trường hợp các trường dữ liệu được phân tách bởi các ký hiệu như ; hay , (delimiter), có thể kết
hợp sử dụng fscanf và fgetc để đọc được từng trường
*/
#include<stdio.h>
enum {SUCCESS, FAIL};
#define MAX_ELEMENT 10 // giới hạn số lượng sản phẩm trong mảng
typedef struct {
    int no; // số thứ tự sản phẩm
    char name[50]; // tên sản phẩm 
    double price; // giá sản phẩm 

} product;
int main(void) {
    FILE *fptr;
    product arr[MAX_ELEMENT]; //mảng chứa sản phẩm
    int count = 0; // biến đếm số lượng sản phẩm đã đọc
    int n; // biến lưu số lượng sản phẩm trong file
    int reval = SUCCESS; // biến lưu kết quả trả về của prog
    printf("Loading file ...\n");
    if((fptr = fopen("product.txt", "r")) == NULL) {
        printf("Cannot open %s.\n", "product.txt");
        reval = FAIL;
    } else {
        while(fscanf(fptr, "%d%s%lf", &arr[count].no, arr[count].name, &arr[count].price) != EOF) {
            // printf("%-6d%-24s%-6.2f\n", arr[count].no, arr[count].name, arr[count].price);
            count ++;
        }
        n = count; // lưu số lượng sản phẩm đã đọc vào biến n
        for (count = 0; count < n; count ++) {
            printf("%-6d%-24s%-6.2f\n", arr[count].no, arr[count].name, arr[count].price);
        }
    }
    fclose(fptr); 
    return reval;
}