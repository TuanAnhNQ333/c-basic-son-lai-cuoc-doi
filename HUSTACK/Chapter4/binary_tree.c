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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    int id;
    struct Node * leftChild;
    struct Node * rightChild;

} Node;
Node * makeNode (int u) {
    Node * p = (Node *) malloc(sizeof(Node));
    p->leftChild = NULL;
    p->rightChild = NULL;
    p->id = u;
    return p;
}
void addLeft(int u, int v, Node * r) {
    Node * p = find(v, r);
    if(p == NULL) {
        return;
    }
    if(p->leftChild != NULL) {
        return;
    }
    Node * q = find (u, r);
    if(q != NULL) {
        return;
    }
    p -> leftChild = makeNode(u);
}
void addRight(int u, int v, Node * r) {
    Node *p = find(v, r);
    if(p == NULL) {
        return;
    }
    if(p->rightChild != NULL) {
        return;
    }
    Node *q = find(u,r) ;
    if(q != NULL) {
        return;
    }
    p->rightChild = makeNode(u);
}
Node *find(int u, Node * r) {
    if(r == NULL) {
        return NULL;
    }
    if(r -> id == u) {
        return r;
    }
    Node *p = find(u, r->leftChild);
    if(p != NULL) {
        return p;
    }
    return find(u, r->rightChild);
}
void preOrder(Node *r) {
    if(r == NULL) {
        return;
    }
    printf("%d ", r->id);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}
void inOrder(Node * r) {
    if(r == NULL) {
        return;
    }
    inOrder(r->leftChild);
    printf("%d ", r->id);
    inOrder(r->rightChild);
}
void postOrder(Node * r) {
    if(r == NULL) {
        return;
    }
    postOrder(r -> leftChild) ;
    postOrder(r -> rightChild);
    printf("%d ", r->id);
}
int main() {
    char cmd[100];
    Node *root = NULL;
    while(1) {
        scanf("%s", cmd);
        if(strcmp(cmd, "*") == 0) {
            break;
        } else if(strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
        } else if(strcmp(cmd, "AddLeft") == 0) {
            int u;
            int v;
            scanf("%d%d", &u, &v);
            addLeft(u, v, root);
        } else if(strcmp(cmd, "AddRight") == 0) {
            int u; int v;
            scanf("%d%d", &u, &v);
            addRight(u,v,root);
        } else if(strcmp(cmd, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if(strcmp(cmd,"PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if(strcmp(cmd, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }
    return 0;
}