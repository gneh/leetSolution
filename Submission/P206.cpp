#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#include <stack>
#include <sstream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        else if (!head->next) {
                return head;
        }
        else {
            ListNode *t0 = head;
            ListNode *t1 = head->next;
            ListNode *t2 = head->next->next;
            while(t2) {
                t1->next = t0;
                t0 = t1;
                t1 = t2;
                t2 = t2->next;
            }
            t1->next = t0;
            head->next = NULL;
            return t1;
        }
    }
};

int main()
{
    // init List Node
    ListNode *p;
    ListNode *head = new ListNode(5);
    p = head;
    p = p->next = new ListNode(8);
//    p = p->next = new ListNode(3);
//    p = p->next = new ListNode(4);
//    p = p->next = new ListNode(7);
    // init complited

    ListNode *r = ( new Solution() ) -> reverseList(head);
    for (ListNode *pi = r; pi; pi = pi->next)
        cout << pi->val << ',';
    cout << endl;
}
