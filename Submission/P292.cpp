#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#define N 10
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

int main()
{
    Solution *slt = new Solution();
    cout << slt->canWinNim(1);
    cout << endl;
//    cout << (4 >> 2);
    cout << endl;
}
