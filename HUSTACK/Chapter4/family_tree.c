/*
Chapter 4 - Family Tree
Trung bình
Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>

Note that: the total number of people in the family is less than or equal to 10
4
Input
Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
Output
Each line is the result of a corresponding query.
Example
Input
Peter Newman
Michael Thomas
John David
Paul Mark
Stephan Mark
Pierre Thomas
Mark Newman
Bill David
David Newman
Thomas Mark
***
descendants Newman
descendants Mark
descendants David
generation Mark
***
Output
10
5
2
2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 25
#define MAX_NODE 10000

typedef struct Node {
    char name[MAX_LEN];
    struct Node *leftMostChild;
    struct Node *rightSibling;
    struct Node *Parent;
} Node;

Node *nodes[MAX_NODE];
int nodeCount = 0;

// Tạo node mới
Node *makeNode(const char *name) {
    Node *p = (Node*)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    p->Parent = NULL;
    return p;
}

// Tìm node theo tên, nếu chưa có thì tạo mới
Node *findOrCreate(char *name) {
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i]->name, name) == 0)
            return nodes[i];
    }
    Node *newNode = makeNode(name);
    nodes[nodeCount++] = newNode;
    return newNode;
}

// Thêm con vào cha
void addChild(Node *child, Node *parent) {
    child->Parent = parent;

    if (parent->leftMostChild == NULL) {
        parent->leftMostChild = child;
    } else {
        Node *p = parent->leftMostChild;
        while (p->rightSibling != NULL) {
            p = p->rightSibling;
        }
        p->rightSibling = child;
    }
}

// Đếm số hậu duệ
int countDescendants(Node *root) {
    int count = 0;
    Node *child = root->leftMostChild;

    while (child != NULL) {
        count++;
        count += countDescendants(child);
        child = child->rightSibling;
    }
    return count;
}

// Tính số thế hệ hậu duệ
int countGenerations(Node *root) {
    int maxDepth = 0;
    Node *child = root->leftMostChild;

    while (child != NULL) {
        int childDepth = 1 + countGenerations(child);
        if (childDepth > maxDepth)
            maxDepth = childDepth;
        child = child->rightSibling;
    }
    return maxDepth;
}

int main() {
    char child[MAX_LEN], parent[MAX_LEN];

    // Đọc block 1: child parent
    while (1) {
        scanf("%s", child);
        if (strcmp(child, "***") == 0) break;
        scanf("%s", parent);

        Node *c = findOrCreate(child);
        Node *p = findOrCreate(parent);
        addChild(c, p);
    }

    // Đọc block 2: câu lệnh truy vấn
    char cmd[MAX_LEN], name[MAX_LEN];

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0) break;

        scanf("%s", name);
        Node *x = findOrCreate(name);

        if (strcmp(cmd, "descendants") == 0) {
            printf("%d\n", countDescendants(x));
        } else if (strcmp(cmd, "generation") == 0) {
            printf("%d\n", countGenerations(x));
        }
    }

    return 0;
}
