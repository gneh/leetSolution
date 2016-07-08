// 88.Merge Sorted Array (E)
// m may not equals to nums1.size()
#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin() + m, nums1.end());
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums2[j] > nums1[i])
                ++i;
            else {
                nums1.insert(nums1.begin() + i, nums2[j]);
                ++i;
                ++m;
                ++j;
            }
        }
        for (; j < n; ++j)
            nums1.push_back(nums2[j]);
    }
};

int main()
{
    int m = 3;
    int n = 1;
    int a1[6] = {1, 2, 3, 11, 22, 33};
    int a2[1] = {1};
    vector<int> nums1(a1, a1 + 6);
    vector<int> nums2(a2, a2 + 1);
    ( new Solution() ) -> merge(nums1, m, nums2, n);
//    nums1.insert(nums1.begin() + 1, 99);
    VECOUT(nums1);
}
