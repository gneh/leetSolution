// 70.Climbing Stairs (E)
// Fibonacci number
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (!n || n == 1)
            return 1;
        else {
            int a = 1, b = 1;
            for (int i = 2; i <= n; ++i) {
                b = a + b;
                a = b - a;
            }
            return b;
        }

    }
};

int main()
{
    for (int i = 0; i < 20; ++i)
    cout << i << ": " << ( new Solution() ) -> climbStairs(i) << endl;
}
