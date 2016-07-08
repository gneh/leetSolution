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
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        deque<TreeNode*> q;
        vector<int> level;
        vector< vector<int> > result;
        if (!root)
            return result;
        q.push_back(root);
        q.push_back(NULL);
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop_front();
            if (!p) {
                q.push_back(NULL);
                result.insert(result.begin(), level);
                vector<int>().swap(level);
                if (q.size() == 1)
                    q.pop_back();
            }
            else {
                level.insert(level.end(), p->val);
                if (p->left) {
                    q.push_back(p->left);
                }
                if (p->right) {
                    q.push_back(p->right);
                }
            }
        }
        return result;
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
    vector< vector<int> > result = slt->levelOrder(root);
    for (int i = 0; i < result.size(); ++i) {
        VECOUT(result[i]);
        cout << endl;
    }

    return 0;
}
