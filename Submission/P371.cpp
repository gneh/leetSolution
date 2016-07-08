// 371.Sum of Two Integers (E)
// Big Manipulation
#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return b ? getSum(a ^ b, (a & b) << 1) : a;
    }
};

int main()
{
    cout << ( new Solution() ) -> getSum(3, 6) << endl;
}
