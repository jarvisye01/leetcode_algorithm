#include <iostream>

class Solution {
public:
    int integerBreak(int n) {
        int dp[59] = {0, 1}, i = 2;

        while (i <= n) {
            int mid = i / 2;
            for (int k = 1; k <= mid; k++) 
                dp[i] = std::max(dp[i], std::max(k, dp[k]) * std::max(i - k, dp[i - k]));
            i++;
        }

        return dp[n];
    }
};

int main(int agrc, char **argv) {
    Solution s;
    for (int i = 2; i <= 58; i++) 
        std::cout << i << " => " << s.integerBreak(i) << std::endl;
    return 0;
}