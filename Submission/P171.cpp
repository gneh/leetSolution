// 171.Excel Sheet Column Number (E)
// When using pow(x, y) in CodeBlocks, precision will loss
#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#define DE cout << "HERE" << endl;
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0, sz = s.length();
        for (int i = 0; i < sz; ++i) {
            int mul = 1;
            for (int j = 0; j < i; ++j)
                mul *= 26;
            sum += (s[sz - 1 - i] - 'A' + 1) * mul;
        }
        return sum;
    }
};

int main()
{
    cout << (new Solution()) -> titleToNumber("AB") << endl;
    return 0;
}
