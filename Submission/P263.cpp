// 263.Ugly Number (E)
#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (!num)
            return false;
        while (!(num % 2))
            num /= 2;
        while (!(num % 3))
            num /= 3;
        while (!(num % 5))
            num /= 5;
        return num == 1 ? true : false;
    }
};

int main()
{
    cout << ( new Solution() ) -> isUgly(12) << endl;
}
