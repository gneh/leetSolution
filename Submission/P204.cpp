// 204.Count Primes (E)
// If Line-18 change to n - 1, the code will meet a runtime problem in OJ
// The commented code is Time limit exceed
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        vector<int> primes(n, false);
        int upper = sqrt(n);
        int counter = 0;
        for (int i = 2; i < n; ++i) {
            if (primes[i])
                continue;
            ++counter;
            if (i > upper)
                continue;
            for (int j = i * i; j < n; j += i)
                primes[j] = true;
        }
        return counter;
    }
};

//class Solution {
//public:
//    vector<int> primes;
//    int countPrimes(int n) {
//        if (n == 0 || n == 1 || n == 2)
//            return 0;
//        primes.push_back(2);
//        for (int i = 3; i < n; i += 2) {
//            vector<int>::iterator it = primes.begin();
//            for (; it != primes.end(); ++it) {
//                if (*it > (i / 2)) {
//                    primes.push_back(i);
//                    break;
//                }
//                if (!(i % *it))
//                    break;
//            }
//        }
//        return primes.size();
//    }
//};

int main()
{
//    cout << (new Solution()) -> countPrimes(5) << ", T: 2" << endl;
//    cout << (new Solution()) -> countPrimes(6) << ", T: 3" << endl;
//    cout << (new Solution()) -> countPrimes(499979) << endl;
    cout << (new Solution()) -> countPrimes(7) << endl;
    return 0;
}
