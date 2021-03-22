#include <iostream>
#include <vector>
#include <limits>

using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // int ret = std::numeric_limits<int>::max(), slow = 0, fast = 0, sz = nums.size();
        int ret = INT32_MAX, slow = 0, fast = 0, sz = nums.size();

        if (sz == 0) return 0;

        int total = nums[fast];
        while (fast < sz) {
            while (fast + 1 < sz && total < s) { total += nums[++fast]; }

            while (slow < fast && total - nums[slow] >= s) { total -= nums[slow++]; }

            if (total >= s) ret = std::min(ret, fast - slow + 1);
            
            if (fast == sz - 1) break;

            total += nums[++fast];
        }
        return ret == INT32_MAX ? 0 : ret;
    }
};

int main(int aegc, char **argv) {
    // int target = 7;
    int target = 3;
    // vector<int> vec = {2, 3, 1, 2, 4, 3};
    vector<int> vec = {1, 1};
    Solution s;
    int ret = s.minSubArrayLen(target, vec);
    std::cout << ret << std::endl;
    return 0;
}