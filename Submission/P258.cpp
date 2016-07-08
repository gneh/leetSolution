// 258.Add Digits (E)

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (!num)
            return 0;
        else
            return (num % 9) ? (num % 9) : 9;
    }
};

int main()
{

}
