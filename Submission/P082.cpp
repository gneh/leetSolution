#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define N 10
#include <deque>
// Ignore Memory leak
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;
        ListNode *p = head;
        ListNode *tmp = head = new ListNode(head->val - 1);
        bool flag = false;
        while (p && p->next) {
            if (p->next->val != p->val) {
                if (flag)
                    if (!p->next->next || p->next->next->val != p->next->val) {
                        flag = false;
                        tmp->next = p->next;
                        tmp = tmp->next;
                        p = p->next;
                    }else ;
                else {
                    tmp->next = p;
                    tmp = tmp->next;
                }
            }
            else
                if (!flag)
                    flag = true;
            p = p->next;
        }
        if (flag)
            tmp->next = NULL;
        return head->next;
    }
};


int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution *slt = new Solution();
    ListNode *result = slt->deleteDuplicates(head);
    ListNode *p = result;
    while (p) {
        cout << p->val << ',';
        p = p->next;
    }

    return 0;
}
