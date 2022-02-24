#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>

// 判断单链表有环
struct Node
{
    int value;
    Node *next;
};

Node *InitLinkList()
{
    Node *head = new Node;
    head->next = NULL;
    head->value = 0;

    Node *tmp = head;

    for (int i = 1; i < 5; i++)
    {
        Node *node = new Node;
        node->next = NULL;
        node->value = i;
        tmp->next = node;
        tmp = tmp->next;
    }
    return head;
}

void PrintLinkList(Node *head)
{
    for (; head != NULL; head = head->next)
    {
        printf("%d,", head->value);
    }
    printf("\n");
}

// 快慢指针
// 若无环  quick是slow的两倍 slow 能追上说明有环
bool HasCircal(Node *head)
{
    if (head->next == NULL || head == NULL || head->next->next == NULL)
    {
        return false;
    }
    Node *quick = head->next->next;
    Node *slow = head;

    while (quick != NULL && quick != slow  && quick->next == NULL && quick->next->next != NULL && slow != NULL  &&slow->next != NULL)
    {
        quick = quick->next->next;
        slow = slow->next;
        if (quick == slow)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = InitLinkList();
    PrintLinkList(head);
    printf("%d\n", HasCircal(head));

    return 0;
}