// 13.Roman to Integer (E)
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman;
        roman.insert(pair<char, int> ('M', 1000));
        roman.insert(pair<char, int> ('D', 500));
        roman.insert(pair<char, int> ('C', 100));
        roman.insert(pair<char, int> ('L', 50));
        roman.insert(pair<char, int> ('X', 10));
        roman.insert(pair<char, int> ('V', 5));
        roman.insert(pair<char, int> ('I', 1));
        if (s.length() == 1)
            return roman[s[0]];
        vector<int> rvec;
        int sz = s.length();
        for (int i = 0; i < sz; ++i)
            rvec.push_back(roman[s[i]]);
        int r = 0, round = rvec[0];
        for (int i = 1; i < sz; ++i) {
            if (rvec[i] > rvec[i - 1]) {
                r += (rvec[i] - round);
                round = 0;
            }
            else if (rvec[i] == rvec[i - 1]) {
                round += rvec[i];
            }
            else if (rvec[i] < rvec[i - 1]) {
                r += round;
                round = rvec[i];
            }
        }
        return r + round;
    }
};

int main()
{
    cout << ( new Solution() ) -> romanToInt("XXIV");
}
