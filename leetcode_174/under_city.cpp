#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M, N;
        if ((M = dungeon.size()) == 0) 
            return -1;
        if ((N = dungeon[0].size()) == 0) 
            return -1;

        int ret = my_calculate(dungeon);
        return ret > 0 ? 1 : -ret + 1;
    }

    int my_calculate(vector<vector<int>>& dungeon) {
        int M = dungeon.size(), N = dungeon[0].size();
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
        dp[M - 1][N - 1] = dungeon[M - 1][N - 1];

        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (i == M - 1 && j == N - 1)
                    continue;
                
                int x = dungeon[i][j];
                int tmin;

                if (i == M - 1)
                    tmin = dp[M - 1][j + 1];
                else if (j == N - 1) 
                    tmin = dp[i + 1][N - 1];
                else 
                    tmin = max(dp[i + 1][j], dp[i][j + 1]);

                if (x > 0 && tmin > 0 || x < 0 && tmin > 0)
                    dp[i][j] = x;
                else 
                    dp[i][j] = x + tmin;
            }
        }
        return dp[0][0];
    }
};


int main(int argc, char **argv) {
    vector<vector<int>> dungeon = {
        {-2, -3, 3}, 
        {-5, -10, 1}, 
        {10, 30, -5}
    };
    Solution s;
    int ret = s.my_calculate(dungeon);
    std::cout << ret << std::endl;
    return 0;
}