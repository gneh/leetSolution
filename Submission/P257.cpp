#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#include <stack>
#include <sstream>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root)
            return result;
        stringstream ss;
        ss << root->val;
        string sval = ss.str();
        if (!root->left && !root->right)
            result.push_back(sval);
        else {
            if (root->left) {
                vector<string> pathl = binaryTreePaths(root->left);
                for (int i = 0; i < pathl.size(); ++i)
                    result.push_back(sval + "->" + pathl[i]);
            }
            if (root->right) {
                vector<string> pathr = binaryTreePaths(root->right);
                for (int i = 0; i < pathr.size(); ++i)
                    result.push_back(sval + "->" + pathr[i]);
            }
        }
        return result;
    }
};

int main()
{
    // init tree
    TreeNode *root = new TreeNode(1);
    TreeNode *p0 = root->left = new TreeNode(2);
    p0->right = new TreeNode(5);
    root->right = new TreeNode(3);
    //-----//

    vector<string> result = ( new Solution() ) -> binaryTreePaths(root);
    VECOUT(result);


}
