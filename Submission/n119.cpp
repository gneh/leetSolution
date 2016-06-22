#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define N 10
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r;
        r.push_back(1);
        if (rowIndex == 0)
            return r;
        r.push_back(1);
        if (rowIndex == 1)
            return r;
        for (int row = 2; row <= rowIndex; ++row) {
            for (int i = 1; i < row; ++i)
                for (int j = 1; i - j >= 0; ++j)
                    j % 2 ? r[i] += r[i - j] : r[i] -= r[i - j];
            r.push_back(1);
        }
        return r;
    }
};


int main()
{
    Solution *slt = new Solution();
    vector<int> result = slt->getRow(4);
    VECOUT(result);
    return 0;
}
