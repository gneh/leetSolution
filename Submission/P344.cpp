// 344.Reverse String (E)
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string r = "";
        for (int i = s.length() - 1; i >= 0; --i)
            r.append(1, s[i]);
        return r;
    }
};

int main()
{
    cout << (new Solution()) -> reverseString("hello") << endl;
    return 0;
}
