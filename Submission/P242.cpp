#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> amaps, amapt;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (amaps.find(c) == amaps.end())
                amaps.insert(pair<char, int>(c, 0));
            amaps[c] += 1;
        }
        for (int i = 0; i < t.size(); ++i) {
            char c = t[i];
            if (amapt.find(c) == amapt.end())
                amapt.insert(pair<char, int>(c, 0));
            amapt[c] += 1;
        }
        int ssize = amaps.size();
        int tsize = amapt.size();
        if (ssize != tsize)
            return false;
        for (map<char, int>::iterator it = amaps.begin(); it != amaps.end(); ++it) {
            char key = it->first;
            if (amapt.find(key) == amapt.end())
                return false;
            else if (amapt[key] != it->second)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution *slt = new Solution();
    if (slt->isAnagram("a", "b"))
        cout << "TRUE" << endl;

//    map<char, int> aMap;
//    aMap.insert(pair<char, int>('a', 2));
//    aMap.insert(pair<char, int>('b', 2));
//    aMap.insert(pair<char, int>('c', 3));
//
//
//    map<char, int> bMap;
//    bMap.insert(pair<char, int>('a', 2));
//    bMap.insert(pair<char, int>('b', 2));
//    bMap.insert(pair<char, int>('c', 3));
//
//    cout << aMap.size();

}
