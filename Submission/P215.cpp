#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#define N 10
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main()
{

    Solution *slt = new Solution();
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    int k = 2;
    int result = slt->findKthLargest(nums, k);
    PRINT(result);
}
