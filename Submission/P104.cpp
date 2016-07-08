// 104.Maximum Depth of Binary Tree (E)
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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(1);
    cout << (new Solution()) -> maxDepth(root) << endl;
    return 0;
}
