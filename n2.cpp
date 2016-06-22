#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define N 10
#include <algorithm>
#include <map>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = new ListNode(-1);
        ListNode *head = p;
        int carry = 0;
        bool end1 = false;
        bool end2 = false;
        while (!end1 || !end2) {
            int v1 = 0, v2 = 0;
            if (!end1) {
                v1 = l1->val;
                if (l1->next)
                    l1 = l1->next;
                else
                    end1 = true;
            }
            if (!end2) {
                v2 = l2->val;
                if (l2->next)
                    l2 = l2->next;
                else
                    end2 = true;
            }
            int sum = v1 + v2 + carry;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;
            p->next = new ListNode(sum);
            p = p->next;
        }
        if (carry)
            p->next = new ListNode(1);
        return head->next;
    }
};


int main()
{
    ListNode *p0 = new ListNode(2);
    p0->next = new ListNode(4);
    p0->next->next = new ListNode(3);

    ListNode *p1 = new ListNode(5);
    p1->next = new ListNode(6);
    p1->next->next = new ListNode(4);

    Solution *slt = new Solution();
    ListNode *r = slt->addTwoNumbers(p0, p1);
    for (ListNode *p = r; p; p = p->next)
        cout << p->val << ',';
}
