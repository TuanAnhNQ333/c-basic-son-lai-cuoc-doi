/*
- make linked list : operator : make Node : value, con trỏ next
- thêm vào đầu insertHead : chỉ thêm nếu >=0 và chưa có
- thêm vào cuối InsertTail : chỉ thêm nếu >=0 và chưa có
- kiểm tra giá trị đã tồn tại trong list (exists)

- print : + nếu k = 0 : hiển thị theo thứ tự hiện tại
          + nếu k = 1 : sắp xếp chẵn lên đầu, lẻ xuống dưới
          ko thay đổi thứ tự tương đối

- free();
- xử lý đầu vào : 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node {
    int value;
    struct Node * next;
}Node;
struct Node *createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = NULL;
    return newNode;
}
void scan(Node * head) {
    while(head != NULL) {
        printf("%d ", head -> value);
        head = head -> next;
    }
}
// them node vao dau linked list
void pushFront(Node** head, int k) {
    Node* newNode = createNode(k);
    newNode -> next = (*head); //*head : dia chi cua node head
    (*head) = newNode;
}
// them node vao cuoi linked list
void pushBack( Node ** head, int k) {
    Node *temp = *head;
    Node *newNode = createNode(k);
    if(*head == NULL) {
        *head = createNode(k);
        return;
    }
    while(temp -> next != NULL) {
        // temp = temp -> next;
        // neu da ton tai, khong them
        if(temp -> value == k) {
            return; 
        }
        temp = temp -> next;
    }
    // neu da ton tai, khong them
    if(temp -> value == k) {
        return ;
    }
    // cho next cua node head tro vao newNode
    temp -> next = newNode;
}
// chen vao giua linked list
/**
 * them node x vao vi tri thu k trong linked list
 * neu k < 1 hoac k > n + 1 thi vi tri chen khong hop le
 * - duyet toi node truoc vi tri can chen : k - 1
 * - cho phan next cua node moi luu node next cua node k - 1
 * - cho phan next cua node k-1 luu node moi
 */
void insert (Node **head, int k, int x) {
    int n = sizeof(*head);
    if(k < 1 || k > n + 1 ) {
        return;
    }
    if(k == 1) {
        pushFront(head, k);
        return;  
    }
    Node *temp = *head;
    for(int i = 1; i <= k - 2; i ++) {
        temp = temp -> next;
    } // temp : k - 1
    Node *newNode = createNode(k);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}
// xoa node dau
/**
 * - cho Node head luu Node thu 2 trong dslk dat la temp
 * - free(temp)
 */
void popFront(Node **head) {
    if (*head == NULL) {
        return ;
    }
    Node * temp = *head;
    *head = temp -> next;
    free(temp);
}
// xoa node cuoi cung cua dslk
/**
 * 
 */
void popBack(Node **head) {
    if(*head == NULL) {
        return ;
    }
    Node *temp = *head; // cho node temp tro toi node dau
    /**
     * neu dslk chi co 1 node, xu ly rieng 
     */
    if(temp -> next == NULL) { 
        *head = NULL;
        free(temp);
        return;
    }
    /**
     * - tim toi node thu 2 tu cuoi ve, goi la temp
     * - cho phan next cua node temp tro vao NULL
     * - free(temp)
     */
    while(temp -> next -> next != NULL) {
        temp = temp -> next;
    } 
    Node *last = temp -> next;
    temp -> next = NULL;
    free(temp);
    
}
int main() {
    Node *head = NULL;
    while(1) {
        printf("1. them vao dau\n");
        printf("2. them vao cuoi\n");
        printf("3. them vao giua\n");
        printf("4. xoa Node dau dslk\n");
        printf("5. xoa Node cuoi dslk\n");
        printf("6. duyet\n");
        printf("0. thoat\n");
        printf("---------------------\n");
        printf("nhap lua chon : ");
        int lc;
        int x; 
        scanf("%d", &lc);
        if(lc == 1) {
            printf("nhap x : \n");
            scanf("%d", &x);
            // them phan tu co gia tri x vao dau linked list
            pushFront(&head, x);
        }
        else if( lc == 2) {
            printf("nhap x : \n");
            scanf("%d", &x);
            // them phan tu co gia tri x vao cuoi linked list
            pushBack(&head, x);
        }
        else if(lc == 3) {
            printf("nhap x : \n");
            scanf("%d", &x);
            int k;
            printf("nhap k : \n");
            scanf("%d", &k);
            insert(&head, k, x);
        }
        else if(lc == 4) {
            popFront(&head);
            printf("\n");
        }
        else if(lc == 5) {
            popBack(&head);
            printf("\n");
        }
        else if(lc == 6) {
            scan(head);
            printf("\n");
        }
        else {
            break;
        }
    }
    scan(head);
    return 0;
} 