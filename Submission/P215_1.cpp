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
        int max_index = 0;
        int km1 = k - 1;
        for (int i = 0; i < k; ++i) {
            max_index = 0;
            for (int j = 0; j < nums.size(); ++j)
                if (nums[j] > nums[max_index])
                    max_index = j;
            if (i != km1)
                nums.erase(nums.begin() + max_index);
        }
        return nums[max_index];
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

//    nums.erase(nums.begin() + 2);
//    VECOUT(nums);
    int k = 4;
    int result = slt->findKthLargest(nums, k);
    PRINT(result);
}
