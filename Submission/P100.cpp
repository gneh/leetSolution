// 100.Same Tree (E)
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if ((!p && q) || (p && !q))
            return false;
        if (p->val != q->val)
            return false;
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(1);

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right = new TreeNode(2);
    cout << (new Solution()) -> isSameTree(root, root1) << endl;
    return 0;
}
