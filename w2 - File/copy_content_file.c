/*
Tạo 1 file văn bản tên : note.txt với nội dung : lý thuyết file, lưu trong cùng thư mục với prog
Viết chương trình đọc từ file trên mỗi lần 1 ký tự, sau đó ghi vào file mới với tên : lab1.txt
*/
#include<stdio.h> //  thư viện chuẩn để xử lý vào ra i/o, printf, fgét, fptr, fputc, fputs

// định nghĩa kiểu enum với 2 giá trị SUCCESS và FAIL để đại diện cho kết quả chạy 
enum{SUCCESS, FAIL};
// hàm CharReadWrite dùng để đọc từng ký tự từ file đầu vào (fin), ghi ra file đầu ra (fout), đồng thời in ký tự lên màn hình
void CharReadWrite(FILE *fin, FILE *fout) {
    int c; // biến lưu giá trị của 1 ký tự đọc được theo dạng int để so sánh với EOF

    // vòng lặp đọc từng ký tự từ file fin cho đến khi gặp EOF (dùng hàm while vì không biết trước số lượng ký tự)
    while((c = fgetc(fin))!= EOF) { // đọc ký tự từ file fin : fgetc trả về giá trị của ký tự đọc được, hoặc EOF nếu kết thúc file
        // nếu ghi ký tự vào file fout không thành công thì báo lỗi và thoát chương
        fputc(c, fout); // write to a file : ghi ký tự vừa đọc được vào file fout
        putchar(c); // display character on the screen : in ký tự đó ra màn hình 
    }
    // lý do dùng fgetc và fputc thay vì fread/fwrite vì xử lý đơn giản từng ký tự, phù hợp với file văn bản nhỏ, dễ hiểu và dễ debug
}
int main (void) {
    FILE *fptr1, *fptr2; // con trỏ FILE để mở và làm việc với 2 file
    char filename1[] = "note.txt"; // tên file fin
    char filename2[] = "lab1.txt"; // ten file fout
    int reval = SUCCESS; // biến lưu kết quả trả về của chương trình, khởi tạo là SUCCESS=

    // mở file fin với chế độ đọc ("r")
    if ((fptr1 = fopen(filename1, "r")) == NULL) {
        printf("Cannot open %s. \n", filename1); // nếu không mở được thì báo FAIL
        reval = FAIL;
    }
    /* fopen trả về giá trị NULL nếu file không tồn tại hoặc không mở được 
    */
   // nếu mở được file đầu vào fin thì tiếp tục mở file đầu ra với chế độ ghi ("w")
    else if ((fptr2 = fopen(filename2, "w")) == NULL) {
        printf("Cannot open %s. \n", filename2); // nếu không mở được thì báo lỗi 
        reval = FAIL;
    }
    else {
        // nếu hàm chạy và thoả mãn mở được cả 2 files thì thực hiện chức năng chính
        CharReadWrite(fptr1, fptr2); // gọi hàm để sao chép nội dung file và in ra màn hình
        // đóng 2 file sau khi hoàn thành
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval; // trả về kết quả của chương trình : SUCCESS hoặc FAIL
 
}