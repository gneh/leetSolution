// 345.Reverse Vowels of a String (E)
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int sz = s.length();
        for (int i = 0, j = sz - 1; i < j; ++i) {
            char si = s[i];
            if (si == 'a' || si == 'e' || si == 'i' || si == 'o' || si == 'u' || si == 'A' || si == 'E' || si == 'I' || si == 'O' || si == 'U') {
                for (; j > i; --j) {
                    char sj = s[j];
                    if (sj == 'a' || sj == 'e' || sj == 'i' || sj == 'o' || sj == 'u' || sj == 'A' || sj == 'E' || sj == 'I' || sj == 'O' || sj == 'U') {
                        s[i] ^= s[j] ^= s[i] ^= s[j];
                        --j;
                        break;
                    }
                }
            }
        }
        return s;
    }
};

int main()
{
    cout << (new Solution()) -> reverseVowels("xaeix") << endl;
    return 0;
}
