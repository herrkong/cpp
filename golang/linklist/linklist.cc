#include <stdio.h>

using namespace std;

struct ListNode
{
    /* data */
    ListNode* next;

};


class Solution {
	public:
		ListNode* reverseList(ListNode* head) {
			ListNode* cur = NULL, *pre = head;
			while (pre != NULL) {
				ListNode* t = pre->next;
				pre->next = cur;
				cur = pre;
				pre = t;
			}
			return cur;
		}
	};

int main() {

     return 0;
}