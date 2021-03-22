#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> vec(sz, 0);

        for (int i = 0; i < sz; i++) {
            int tm = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) 
                    tm = std::max(vec[j] + 1, tm);
            }
            vec[i] = tm;
        }

        auto iter = std::max_element(vec.begin(), vec.end());
        return  iter != vec.end() ? *iter : 0;
    }

    int lengthOfLISII(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;

        int dp[sz + 1], len = 1;
        dp[len] = nums[0];

        for (int i = 1; i < sz; i++) {
            if (nums[i] > dp[len]) 
                dp[++len] = nums[i];
            else {
                int l = 1, h = len, pos = 0;
                while (l <= h) {
                    int mid = l + (h - l) / 2;
                    if (dp[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else 
                        h = mid - 1;
                }
                dp[pos + 1] = nums[i];
            }
        }

        return len;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> num = {10, 9, 2, 5, 3, 7, 101, 18};
    int ret = s.lengthOfLIS(num);
    std::cout << "lengthOfLIS = " << ret << std::endl;
    std::cout << "lengthOfLISII = " << s.lengthOfLISII(num) << std::endl;
    return 0;
}