#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define N 10
#include <algorithm>
#include <map>

// Ignore Memory leak
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int sz = nums.size();
        map<int, int> hsm;
        for (int i = 0; i < sz; ++i) {
            int x = nums[i];
            if (hsm.find(x) != hsm.end())
                if ((i - hsm.find(x)->second) <= k)
                    return true;
            hsm[x] = i;
        }
        return false;
    }
};


int main()
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(7);
    Solution *slt = new Solution();
    bool result = slt->containsNearbyDuplicate(nums, 3);
    cout << result << endl;

//    map<int, int> mp;
//    mp[0] = 1;
//    mp[1] = 4;
//    mp[2] = 3;
//    mp[3] = 4;
//    cout << (mp.find(4) == mp.end());
//
//
//    cout << endl;
}
