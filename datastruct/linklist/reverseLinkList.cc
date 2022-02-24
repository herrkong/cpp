#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>

typedef std::map<int,int> MyMap;

//  反转链表
struct Node
{
    int value;
    Node *next;
};


// class Solution {
// 	public:
// 		ListNode* reverseList(ListNode* head) {
// 			ListNode* cur = NULL, *pre = head;
// 			while (pre != NULL) {
// 				ListNode* t = pre->next;
// 				pre->next = cur;
// 				cur = pre;
// 				pre = t;
// 			}
// 			return cur;
// 		}
// 	};

// pre pcur pnext 
// 双指针移动 pcur 比 pre 快一步
 
Node* ReverseLinkList(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }

    Node * pre = NULL;
    Node * pcur = head;
  
    for(;pcur != NULL;){
        Node * pnext = pcur->next;
        pcur->next = pre;
        pre = pcur;
        pcur = pnext;
    }
   
    return pre;

}

Node * InitLinkList(){
    Node * head = new Node;
    head ->next = NULL;
    head->value = 0;
    Node * tmp = head;

    for (int i = 1 ; i< 5 ;i++){
        Node* node = new Node;
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


int main()
{
    Node * head = InitLinkList();
    head = ReverseLinkList(head);
    PrintLinkList(head);

    return 0;
}