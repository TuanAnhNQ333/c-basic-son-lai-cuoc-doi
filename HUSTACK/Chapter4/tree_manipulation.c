/*
Chapter 4 - Tree manipulation & Traversal
Trung bình
Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
· PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
· InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
· PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
Ví dụ
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
InOrder
Insert 5 11
Insert 4 11
Insert 8 3
PreOrder
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
InOrder
PostOrder
*
Kết quả
11 10 1 3
10 11 5 4 1 3 8
5 11 6 4 9 10 1 8 3 2 7
5 6 9 4 11 1 8 2 7 3 10
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cây n-ary với typedef
typedef struct Node {
    int id;
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;

// Tạo nút mới
Node* makeNode(int u) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

// Tìm nút có id = u
Node* find(Node* r, int u) {
    if (r == NULL) return NULL;
    if (r->id == u) return r;
    Node* p = r->leftMostChild;
    while (p != NULL) {
        Node* q = find(p, u);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

// Kiểm tra nút đã tồn tại chưa
int exists(Node* r, int u) {
    return find(r, u) != NULL;
}

// Chèn nút u vào nút v
void insert(Node* r, int u, int v) {
    if (r == NULL) return;
    if (exists(r, u)) return; // đã tồn tại
    Node* parent = find(r, v);
    if (parent == NULL) return; // nút v không tồn tại
    Node* q = makeNode(u);
    if (parent->leftMostChild == NULL) {
        parent->leftMostChild = q;
    } else {
        Node* p = parent->leftMostChild;
        while (p->rightSibling != NULL) p = p->rightSibling;
        p->rightSibling = q;
    }
}

// Duyệt cây trước (PreOrder)
void preOrder(Node* r) {
    if (r == NULL) return;
    printf("%d ", r->id);
    Node* p = r->leftMostChild;
    while (p != NULL) {
        preOrder(p);
        p = p->rightSibling;
    }
}

// Duyệt cây giữa (InOrder) cho cây n-ary
void inOrder(Node* r) {
    if (r == NULL) return;
    Node* p = r->leftMostChild;
    int n = 0;
    Node* temp = p;
    while (temp != NULL) { // đếm số con
        n++;
        temp = temp->rightSibling;
    }
    int cnt = 0;
    temp = p;
    while (cnt < n / 2 && temp != NULL) { // duyệt nửa đầu con
        inOrder(temp);
        temp = temp->rightSibling;
        cnt++;
    }
    printf("%d ", r->id); // root
    while (temp != NULL) { // duyệt nửa sau con
        inOrder(temp);
        temp = temp->rightSibling;
    }
}

// Duyệt cây sau (PostOrder)
void postOrder(Node* r) {
    if (r == NULL) return;
    Node* p = r->leftMostChild;
    while (p != NULL) {
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ", r->id);
}

// Giải phóng cây
void freeTree(Node* r) {
    if (r == NULL) return;
    Node* p = r->leftMostChild;
    while (p != NULL) {
        Node* np = p->rightSibling;
        freeTree(p);
        p = np;
    }
    free(r);
}

// Hàm xử lý dữ liệu
void solve() {
    Node* root = NULL;
    char cmd[50];
    while (1) {
        if (scanf("%s", cmd) != 1) break;
        if (strcmp(cmd, "*") == 0) break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            int id;
            scanf("%d", &id);
            root = makeNode(id);
        } else if (strcmp(cmd, "Insert") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            insert(root, u, v);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }
    freeTree(root);
}

int main() {
    solve();
    return 0;
}
