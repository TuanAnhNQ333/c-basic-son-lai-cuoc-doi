/*
Chapter 4 - Tree manipulation query depth - height
Trung bình
Mỗi nút trên 1 cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không thêm mới)
· Height u:  Tính và trả về độ cao của nút u
· Depth u: Tính và trả về độ sâu của nút u
Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
· Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
· Kết quả: ghi ra mỗi dòng kết quả của các lệnh Height và Depth tương ứng đọc được từ đầu vào
Ví dụ:
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
Insert 5 11
Insert 4 11
Height 10
Depth 10
Insert 8 3
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
Height 10
Depth 10
Depth 3
*
Kết quả
3
1
4
1
2
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
    int id;
    struct _node* parent;
    struct _node* leftmostchild;
    struct _node* rightsibling;
} NODE;

typedef struct _tree
{
    NODE* root;
} TREE;

TREE g_tree;

NODE* CreateNode(int id)
{
    NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
    newNode->id = id;
    return newNode;
}

NODE* Find(const NODE* root, int v)
{
    if (root == NULL)
        return NULL;
    if (root->id == v)
        return (NODE*)root;

    NODE* tmp = root->leftmostchild;
    while (tmp != NULL)
    {
        NODE* result = Find(tmp, v);
        if (result != NULL)
            return result;

        tmp = tmp->rightsibling;
    }
    return NULL;
}

void MakeRoot(TREE* tree, int id)
{
    tree->root = CreateNode(id);
}

void Insert(const TREE tree, int u, int v)
{
    NODE* nodeU = Find(tree.root, u);
    if (nodeU != NULL)
        return;

    NODE* nodeV = Find(tree.root, v);
    if (nodeV == NULL)
        return;

    NODE* newNode = CreateNode(u);
    newNode->parent = nodeV;

    if (nodeV->leftmostchild == NULL)
    {
        nodeV->leftmostchild = newNode;
    }
    else
    {
        NODE* tmp = nodeV->leftmostchild;
        while (tmp->rightsibling != NULL)
            tmp = tmp->rightsibling;
        tmp->rightsibling = newNode;
    }
}

int NodeHeight(const NODE* node)
{
    int maxH = 1;
    NODE* tmp = node->leftmostchild;
    while (tmp != NULL)
    {
        int h = NodeHeight(tmp);
        if (h + 1 > maxH)
            maxH = h + 1;
        tmp = tmp->rightsibling;
    }
    return maxH;
}

int TreeHeight(const TREE tree, int v)
{
    NODE* tmp = Find(tree.root, v);
    if (tmp == NULL)
        return -1;
    return NodeHeight(tmp);
}

int Depth(const TREE tree, int v)
{
    NODE* nodeV = Find(tree.root, v);
    if (nodeV == NULL)
        return -1;

    int d = 1;
    while (nodeV->parent != NULL)
    {
        d++;
        nodeV = nodeV->parent;
    }
    return d;
}

int main()
{
    char line[1024];

    while (1)
    {
        if (!fgets(line, sizeof(line), stdin))
            break;

        if (line[0] == '*')
            break;

        char command[64];
        sscanf(line, "%s", command);

        if (strcmp(command, "MakeRoot") == 0)
        {
            int v;
            sscanf(line, "%*s %d", &v);
            MakeRoot(&g_tree, v);
        }
        else if (strcmp(command, "Insert") == 0)
        {
            int u, v;
            sscanf(line, "%*s %d %d", &u, &v);
            Insert(g_tree, u, v);
        }
        else if (strcmp(command, "Height") == 0)
        {
            int v;
            sscanf(line, "%*s %d", &v);
            printf("%d\n", TreeHeight(g_tree, v));
        }
        else if (strcmp(command, "Depth") == 0)
        {
            int v;
            sscanf(line, "%*s %d", &v);
            printf("%d\n", Depth(g_tree, v));
        }
    }
    return 0;
}
