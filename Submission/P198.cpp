// 198.House Robber (E)
/* P(0) = 0
 * P(1) = M(1)
 * P(N) = max(P(N) + P(N-2), P(N-1))
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        nums.insert(nums.begin(), 0);
        for (int i = 2; i < nums.size(); ++i)
            if ((nums[i] + nums[i - 2]) > nums[i - 1])
                nums[i] = nums[i] + nums[i - 2];
            else
                nums[i] = nums[i - 1];
        return nums[nums.size() - 1];
    }
};

int main()
{
    int arr[5] = {5, 19, 7, 3, 18};
    vector<int> nums(arr, arr + 5);
    cout << ( new Solution() ) -> rob(nums) << endl;
}
