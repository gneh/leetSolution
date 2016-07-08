// 283.Move Zeroes (E)
#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n;) {
            if (!nums[i]) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                --n;
            }
            else
                ++i;
        }
    }
};

int main()
{
    int arr[5] = {0, 1, 0, 3, 12};
    vector<int> ivec(arr, arr + 5);
    (new Solution()) -> moveZeroes(ivec);
    VECOUT(ivec);
}
