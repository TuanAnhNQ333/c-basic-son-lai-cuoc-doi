#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * cau truc con tro kieu node
 */
typedef struct node_t {
    char ten[21];
    struct node_t *next;
} node;
/**
 * khoi tao cac node
 */
node *head0 = NULL;
node *head1 = NULL;
node *tail0 = NULL;
node *tail1 = NULL;
node *makeNode(char s[21]) {
    // cap phat dong cho 1 node moi
    node *New = (node *)malloc(sizeof(node));
    // sao chep ten s vao ten cua node moi
    strcpy(New -> ten, s);
    // khoi tao node moi la null
    New -> next = NULL;
    return New;
}
void enqueue0(char s[21]) {
    node *nam = makeNode(s);
    if(head0 == NULL && tail0 == NULL) {
        head0 = nam;
        tail0 = nam;
    } else {
        tail0 -> next = nam;
        tail0 = nam;
    }
}
void enqueue1(char s[21]) {
    node *nu = makeNode(s);
    if(head1 == NULL && tail1 == NULL) {
        head1 = nu;
        tail1 = nu;
    } else {
        tail1 -> next = nu;
        tail1 = nu;
    }
}
void dequeue0() {
    node *temp = head0;
    char v[21];
    strcpy(v, head0 -> ten);
    head0 = head0 -> next;
    free(temp);
    if(head0 == NULL) {
        tail0 = NULL;
    }
    printf("Welcome %s\n", v);
}
void dequeue1() {
    node *temp = head1;
    char v[21];
    strcpy(v, head1 -> ten);
    head1 = head1 -> next;
    free(temp);
    if(head1 == NULL) {
        tail1 = NULL;
    }
    printf("Welcome %s\n", v);
}
void freespace() {
    while(head1 != NULL) {
        node *p = head1;
        head1 = head1 -> next;
        free(p);
    }
    while(head0 != NULL) {
        node *p = head0;
        head0 = head0 -> next;
        free(p);
    }
}
int main() {
    char cmd[100];
    while(1) {
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) {
            freespace() ;
            break;
        }
    }
}