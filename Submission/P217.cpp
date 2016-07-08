#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define N 10
#include <algorithm>

// Ignore Memory leak
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (!nums.size())
            return false;
        sort(nums.begin(), nums.end());
        int tmp = nums[0] - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == tmp)
                return true;
            else
                tmp = nums[i];
        }
        return false;
    }
};


int main()
{
    vector<int> nums;
    nums.push_back(5);
//    nums.push_back(6);
//    nums.push_back(25);
//    nums.push_back(1);
//    nums.push_back(7);
//    nums.push_back(4);

    Solution *slt = new Solution();
    bool result = slt->containsDuplicate(nums);
    cout << result << endl;
    return 0;
}
