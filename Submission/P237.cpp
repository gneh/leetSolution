#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
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
    void deleteNode(ListNode* node) {
        ListNode *p = node;
        for (; p->next->next; p = p->next)
            p->val ^= p->next->val ^= p->val ^= p->next->val;
        p->val ^= p->next->val ^= p->val ^= p->next->val;
        p->next = NULL;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p = p->next = new ListNode(2);
    p = p->next = new ListNode(3);
    p = p->next = new ListNode(4);
    p = p->next = new ListNode(5);
    ( new Solution() ) -> deleteNode(head->next->next);
    for (ListNode *pi = head; pi; pi = pi->next)
        cout << pi->val << ',';
    cout << endl;
}
