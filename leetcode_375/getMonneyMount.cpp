#include <iostream>
#include <limits>

class Solution {
public:
// error
    int getMoneyAmount(int n) {
        int dp[n + 4];
        for (int i = 0; i < n + 1; i++)
            dp[i] = std::numeric_limits<int>::max();
        dp[0] = 0, dp[1] = 0, dp[2] = 1, dp[3] = 2;
        for (int i = 4; i <= n; i++) {
            // dp[i] = std::max(i - 3 + dp[i - 4], i - 3 + (i - 1));
            int k = 3, total = i - 1;
            while (i - k > 0) {
                if (i == 124)
                    std::cout << "i - k = " << i - k << ", " << "total = " << total << ", dp[" << i - k - 1 << "] = " << dp[i - k - 1] << std::endl;
                dp[i] = std::min(dp[i], std::max(i - k + dp[i - k - 1], i - k + total));
                if (i == 124)
                    std::cout << "dp[" << i << "] = " << dp[i] << std::endl;
                total += i - k;
                k = k * 2 + 1;
            }
        }

        return dp[n];
    }
};

int main(int argc, char **argv) {
    Solution s;
    // for (int i = 1; i <= 200; i++)
    //     std::cout << i << " => " << s.getMoneyAmount(i) << std::endl;
    std::cout << s.getMoneyAmount(124) << std::endl;
    return 0;
}