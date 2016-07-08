// 58.Length of Last Word (E)
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1, last = 0;
        for (; i >= 0 && s[i] == ' '; --i);
        for (; i >= 0 && s[i] != ' '; --i)
            ++last;
        return last;
    }
};

int main()
{
    cout << (new Solution()) -> lengthOfLastWord(" ") << endl;
    return 0;
}
