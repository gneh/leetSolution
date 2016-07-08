//The space complexity is O(1)
#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k = k % sz;
        if (k == 0)
            return ;
        int c = 1;
        for (; c <= k; ++c)
            if (!((c * sz) % k))
                break;
        int ns = c * sz / k;
        int r = k / c;
        int tmp = 0;
        for (int i = 0; i < r; ++i) {
            tmp = nums[i];
            nums[i] = nums[(i - k + sz) % sz];
            for (int j = 1; j < ns; ++j) {
                int n = (j * k) % sz + i;
                nums[n] ^= tmp ^= nums[n] ^= tmp;
            }
        }
    }
};

int main()
{
    int x[1] = {1};
    vector<int> nums(x, x + 1);

    Solution *slt = new Solution();
    slt->rotate(nums, 1);
    VECOUT(nums);
//    int a = 34, b = 84;
//    a ^= b ^= a ^= b;
//    cout << a << ',' << b << endl;
}
