#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>

struct Node
{
    int value;
    Node *next;
};

void PrintLinkList(Node *head)
{
    for (; head != NULL; head = head->next)
    {
        printf("%d,", head->value);
    }
    printf("\n");
}

// 尾插法建立链表
Node *InitLinkList(Node *head)
{
    Node *tail = head;
    for (int i = 1; i < 5; i++)
    {
        Node *node = new Node;
        node->next = NULL;
        node->value = i;
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;
    return head;
}

void DeleteNode(Node *head, int target)
{
    if (head == NULL)
    {
        return;
    }
    Node *pre = head;

    for (; pre != NULL; pre = pre->next)
    {
        Node *pcur = pre->next;
        if (pcur->value == target)
        {
            Node *pnext = pcur->next;
            pre->next = pnext;
        }
    }
}

int main()
{
    Node *head = new Node;
    head->next = NULL;
    head->value = 0;
    InitLinkList(head);
    DeleteNode(head, 4);
    PrintLinkList(head);

    return 0;
}