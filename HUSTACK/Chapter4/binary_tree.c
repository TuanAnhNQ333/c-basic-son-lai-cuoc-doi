/*
Chapter 4 - Binary Tree Manipulation & Traversal
Dễ
Mỗi nút của một cây nhị phân T có trường id (định danh của nút, id không trùng lặp nhau). Thực hiện chuỗi các thao tác sau đây trên cây T (ban đầu, T là cây rỗng)
MakeRoot u: tạo một nút gốc có id bằng u
AddLeft u v: tạo một nút có id = u và chèn vào vị trí con trái của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con trái rồi)
AddRight u v: tạo một nút có id = u và chèn vào vị trí con phải của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con phải rồi)
PreOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự trước (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
InOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự giữa (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
PostOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự sau (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
 
Input
Mỗi dòng là 1 trong số cách thao tác với định dạng được mô tả ở trên (thao tác MakeRoot chỉ xuất hiện đúng 1 lần và luôn ở ngay dòng đầu tiên). Kết thúc của dữ liệu input là dòng chứa duy nhất ký tự *

Output
Ghi ra trên 1 dòng kết quả của 1 trong số 3 thao tác InOrder, PreOrder, PostOrder mô tả ở trên

Example
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 4 3
AddRight 5 2
PreOrder
AddLeft 6 5
AddRight 7 5
InOrder
*

Output
1 2 5 3 4
2 6 5 7 1 4 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node* makeNode(int u);
Node* find(int u, Node* r);
void addLeft(int u, int v, Node* r);
void addRight(int u, int v, Node* r);

void collectPre(Node* r, int* a, int* n) {
    if (!r) return;
    a[(*n)++] = r->id;
    collectPre(r->leftChild, a, n);
    collectPre(r->rightChild, a, n);
}

void collectIn(Node* r, int* a, int* n) {
    if (!r) return;
    collectIn(r->leftChild, a, n);
    a[(*n)++] = r->id;
    collectIn(r->rightChild, a, n);
}

void collectPost(Node* r, int* a, int* n) {
    if (!r) return;
    collectPost(r->leftChild, a, n);
    collectPost(r->rightChild, a, n);
    a[(*n)++] = r->id;
}

Node* makeNode(int u) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node* find(int u, Node* r) {
    if (!r) return NULL;
    if (r->id == u) return r;
    Node* p = find(u, r->leftChild);
    if (p) return p;
    return find(u, r->rightChild);
}

void addLeft(int u, int v, Node* r) {
    Node* p = find(v, r);
    if (!p) return;
    if (p->leftChild) return;
    if (find(u, r)) return;
    p->leftChild = makeNode(u);
}

void addRight(int u, int v, Node* r) {
    Node* p = find(v, r);
    if (!p) return;
    if (p->rightChild) return;
    if (find(u, r)) return;
    p->rightChild = makeNode(u);
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main() {
    char cmd[100];
    Node* root = NULL;

    int a[10000]; // lưu kết quả duyệt cây

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0) break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
        }
        else if (strcmp(cmd, "AddLeft") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addLeft(u, v, root);
        }
        else if (strcmp(cmd, "AddRight") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addRight(u, v, root);
        }
        else if (strcmp(cmd, "PreOrder") == 0) {
            int n = 0;
            collectPre(root, a, &n);
            printArray(a, n);
        }
        else if (strcmp(cmd, "InOrder") == 0) {
            int n = 0;
            collectIn(root, a, &n);
            printArray(a, n);
        }
        else if (strcmp(cmd, "PostOrder") == 0) {
            int n = 0;
            collectPost(root, a, &n);
            printArray(a, n);
        }
    }
    return 0;
}
