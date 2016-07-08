#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        int map[100][100] = {0};
        for (int i = 1; i < m; ++i)
            map[i][0] = 1;
        for (int i = 1; i < n; ++i)
            map[0][i] = 1;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                map[i][j] = map[i - 1][j] + map[i][j - 1];
        return map[m - 1][n - 1];
    }
};


int main()
{
    Solution *slt = new Solution();
    int result = slt->uniquePaths(23, 12);
    cout << result << endl;
    return 0;
}
