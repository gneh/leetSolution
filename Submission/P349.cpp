// 349.Intersection of Two Arrays (E)
// Using map
// Sort can be considered
#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r;
        map<int, bool> map1, map2, mapr;
        for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
            map1[*it] = true;
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
            map2[*it] = true;
        for (map<int, bool>::iterator it = map1.begin(); it != map1.end(); ++it)
            if (map2[it->first])
                mapr[it->first] = true;
        for (map<int, bool>::iterator it = mapr.begin(); it != mapr.end(); ++it)
            r.push_back(it->first);
        return r;
    }
};

int main()
{
    int arr1[7] = {0, 1, 2, 2, 1, 5, 3};
    vector<int> nums1(arr1, arr1 + 7);
    int arr2[4] = {2, 2, 5, 5};
    vector<int> nums2(arr2, arr2 + 4);
    vector<int> r = (new Solution()) -> intersection(nums1, nums2);
    VECOUT(r);
}
