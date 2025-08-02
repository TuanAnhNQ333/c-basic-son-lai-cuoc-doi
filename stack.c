#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_t
{
    char ten[21];
    struct node_t *next;
} node;
node *head0 = NULL;
node *head1 = NULL;
node *tail0 = NULL;
node *tail1 = NULL;
node *makeNode(char s[21])
{
    node *New = (node *)malloc(sizeof(node));
    strcpy(New->ten, s);
    New->next = NULL;
    return New;
}
void enqueue0(char s[21])
{
    node *nam = makeNode(s);
    if (head0 == NULL && tail0 == NULL)
    {
        head0 = nam;
        tail0 = nam;
    }
    else
    {
        tail0->next = nam;
        tail0 = nam;
    }
}
void dequeue0()
{
    node *tmp = head0;
    char v[21];
    strcpy(v, head0->ten);
    head0 = head0->next;
    free(tmp);
    if (head0 == NULL)
        tail0 = NULL;
    printf("Welcome %s\n", v);
}
void enqueue1(char s[21])
{
    node *nu = makeNode(s);
    if (head1 == NULL && tail1 == NULL)
    {
        head1 = nu;
        tail1 = nu;
    }
    else
    {
        tail1->next = nu;
        tail1 = nu;
    }
}
void dequeue1()
{
    node *tmp = head1;
    char v[21];
    strcpy(v, head1->ten);
    head1 = head1->next;
    free(tmp);
    if (head1 == NULL)
        tail1 = NULL;
    printf("Welcome %s\n", v);
}
void giaiphong()
{
    while (head1 != NULL)
    {
        node *p = head1;
        head1 = head1->next;
        free(p);
    }
    while (head0 != NULL)
    {
        node *p = head0;
        head0 = head0->next;
        free(p);
    }
}
int main()
{
    char cmd[100];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
        {
            giaiphong();
            break;
        }
        else if (strcmp(cmd, "ENQUEUE") == 0)
        {
            int gt;
            scanf("%d", &gt);
            char s[20];
            scanf("%s", s);
            if (gt == 0)
                enqueue0(s);
            if (gt == 1)
                enqueue1(s);
        }
        else if (strcmp(cmd, "DEQUEUE") == 0)
        {
            int gt;
            scanf("%d", &gt);
            if (gt == 0)
            {
               if (head0 == NULL)
                    printf("NULL\n");
                else
                {
                    dequeue0();
                }
            }
            if (gt == 1)
            {
                if (head1 == NULL)
                    printf("NULL\n");
                else
                {
                    dequeue1();
                }
            }
        }
    }
    return 0;
}
