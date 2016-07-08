// 342.Power of Four (E)
// Bit Manipulation
// Attention: Negative numbers
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (!num)
            return false;
        if (num >> 31)
            return false;
        if ((num & 0x55555555) != num)
            return false;
        if (((num - 1) & num))
            return false;
        return true;
    }
};

int main()
{
    cout << ( new Solution() ) -> isPowerOfFour(1) << endl;
//    cout << ( new Solution() ) -> isPowerOfFour(-128) << endl;
    cout << (128 & 0x55555555) << endl;
//    cout << sizeof();
}
