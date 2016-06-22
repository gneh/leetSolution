#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define N 10
#include <deque>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        deque<TreeNode*> q;
        q.push_back(root);
        bool isdown = true;
        int current = 0;
        int backplus = 0;
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            if (!tmp->left && !tmp->right) {
                if (tmp->val == sum)
                    return true;
            }
            if (tmp->left) {
                tmp->left->val += tmp->val;
                q.push_back(tmp->left);
            }
            if (tmp->right) {
                tmp->right->val += tmp->val;
                q.push_back(tmp->right);
            }
            q.pop_front();
        }
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *t0 = new TreeNode(9);
    TreeNode *t1 = new TreeNode(20);
    TreeNode *t2 = new TreeNode(15);
    TreeNode *t3 = new TreeNode(7);
    root->left = t0;
    root->right = t1;
    t1->left = t2;
    t1->right = t3;

    Solution *slt = new Solution();
    bool result = slt->hasPathSum(root, 31);
    cout << result << endl;


    return 0;
}
