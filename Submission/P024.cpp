// 24.Swap Nodes in Pairs (E)
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;
        ListNode *t0 = head;
        ListNode *t1 = head->next;
        head = t1;
        while (true) {
            if (t1->next) {
                ListNode *t = t1->next;
                t1->next = t0;
                if (t->next) {
                    t0->next = t->next;
                    t0 = t;
                    t1 = t->next;
                }
                else {
                    t0->next = t;
                    break;
                }
            }
            else {
                t1->next = t0;
                t0->next = NULL;
                break;
            }
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *p = head;
//    p = p->next = new ListNode(2);
//    p = p->next = new ListNode(3);
//    p = p->next = new ListNode(4);
//    p = p->next = new ListNode(5);
    ListNode *r = (new Solution())->swapPairs(head);
    for (ListNode *p = r; p; p = p->next)
        cout << p->val << ',';
}
