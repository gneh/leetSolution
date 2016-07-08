// 231.Power of Two (E)
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return ((n - 1) & n) ? false : true;
    }
};

int main()
{
    cout << ( new Solution() ) -> isPowerOfTwo(16);
}
