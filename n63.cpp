#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        int map[100][100] = {0};
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 1) {
            for (int i = 0; i < n; ++i)
                if (obstacleGrid[0][i])
                    return 0;
            return 1;
        }
        if (n == 1) {
            for (int i = 0; i < m; ++i)
                if (obstacleGrid[i][0])
                    return 0;
            return 1;
        }
        int flag = 0;
        for (int i = 0; i < m; ++i) {
            if (!flag)
                if (!obstacleGrid[i][0])
                    map[i][0] = 1;
                else {
                    flag = 1;
                    map[i][0] = 0;
                }
            else
                map[i][0] = 0;
        }
        flag = 0;
        for (int i = 0; i < n; ++i) {
            if (!flag)
                if (!obstacleGrid[0][i])
                    map[0][i] = 1;
                else {
                    flag = 1;
                    map[0][i] = 0;
                }
            else
                map[0][i] = 0;
        }
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (obstacleGrid[i][j])
                    map[i][j] = 0;
                else
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
        return map[m - 1][n - 1];
    }
};


int main()
{
    Solution *slt = new Solution();

//    vector<int> x0, x1, x2;
//    x0.insert(x0.end(), 0);
//    x0.insert(x0.end(), 0);
//    x0.insert(x0.end(), 0);
//    x1.insert(x1.end(), 0);
//    x1.insert(x1.end(), 1);
//    x1.insert(x1.end(), 0);
//    x2.insert(x2.end(), 0);
//    x2.insert(x2.end(), 0);
//    x2.insert(x2.end(), 0);
//    vector< vector<int> > s;
//    s.insert(s.end(), x0);
//    s.insert(s.end(), x1);
//    s.insert(s.end(), x2);
    vector<int> x0, x1;
    x0.insert(x0.end(), 0);
    x1.insert(x1.end(), 1);
    vector< vector<int> > s;
    s.insert(s.end(), x0);
    s.insert(s.end(), x1);
    int result = slt->uniquePathsWithObstacles(s);
    cout << result << endl;
    return 0;
}
