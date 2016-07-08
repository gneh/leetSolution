// 27.Remove Element (E)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size(), count = 0;
        for (int i = 0; i < sz; ++i)
            if (nums[i] != val)
                ++count;
            else {
                nums.erase(nums.begin() + i);
                --sz;
                --i;
            }
        return count;
    }
};

int main()
{
    int arr[5] = {2, 4, 5, 5, 3};
    vector<int> nums(arr, arr + 5);
    cout << (new Solution()) -> removeElement(nums, 5) << endl;
}
