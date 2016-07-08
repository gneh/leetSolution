// 66.Plus One (E)
#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i)
            if (++digits[i] == 10)
                digits[i] = 0;
            else
                return digits;
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    int arr[5] = {9, 9, 9, 9, 9};
    vector<int> nums(arr, arr + 5);
    vector<int> result = (new Solution()) -> plusOne(nums);
    VECOUT(result);
}
