// 226.Invert Binary Tree (E)
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;
        else {
            TreeNode *p = root->left;
            root->left = root->right;
            root->right = p;
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root = (new Solution()) -> invertTree(root);
    cout << root->val << endl;
    cout << root->left->val << ',' << root->right->val << endl;
    cout << root->left->left->val << ',' << root->left->right->val << ',' << root->right->left->val << ',' << root->right->right->val << endl;
}
