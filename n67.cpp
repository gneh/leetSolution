#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define N 10
#include <algorithm>
#include <map>

// Ignore Memory leak
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        if (alen >= blen)
            for (int i = 0; i < alen - blen; ++i)
                b = '0' + b;
        else
            for (int i = 0; i < blen - alen; ++i)
                a = '0' + a;
        int strlen = a.length();
        string result = "";
        bool carry = false;
        for (int i = strlen - 1; i >= 0; --i) {
            char ai = a[i];
            char bi = b[i];
            char cur = '0';
            if (ai == '1' && bi == '1')
                cur = '2';
            if ((ai == '1' && bi == '0') || (ai == '0' && bi == '1'))
                cur = '1';
            if (ai == '0' && bi == '0')
                cur = '0';
            if (carry)
                if (cur == '0') {
                    cur = '1';
                    carry = false;
                }
                else if (cur == '1')
                    cur = '0';
                else
                    cur = '1';
            else if (cur == '2') {
                cur = '0';
                carry = true;
            }
            result = cur + result;
        }
        if (carry)
            result = '1' + result;
        return result;
    }
};


int main()
{
    Solution *slt = new Solution();
    string a = "1111100";
    string b = "0110101";
    cout << slt->addBinary(a, b);
    cout << endl;
}
