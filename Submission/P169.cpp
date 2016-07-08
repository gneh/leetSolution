#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> amap;
        int n = nums.size();
        int hn = n / 2;
        for (int i = 0; i < n; ++i) {
            if (amap.find(nums[i]) == amap.end())
                amap.insert(pair<int, int>(nums[i], 0));
            amap[nums[i]] += 1;
        }
        for (map<int, int>::iterator it = amap.begin(); it != amap.end(); ++it)
            if (it->second > hn)
                return it->first;
        return 0;
    }
};

int main()
{
    int arr[10] = {1, 3, 3, 3, 3, 3, 3, 2, 5, 6};
    vector<int> nums(arr, arr + 10);
    int result = ( new Solution() ) -> majorityElement(nums);
    cout << result << endl;
}
