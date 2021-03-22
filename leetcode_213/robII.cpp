#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int robAux(const vector<int>& nums) {
        int sz = nums.size();

        int next = 0, next_next = 0, cur;

        for (int i = sz - 1; i >= 0; i--) {
            cur = std::max(nums[i] + next_next, next);
            next_next= next;
            next = cur;
        }
        return cur;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int ret1 = robAux(vector<int>(nums.begin(), nums.end() - 1));
        int ret2 = robAux(vector<int>(nums.begin() + 1, nums.end()));
        return std::max(ret1, ret2);
    }
};

int main(int argc, char **argv) {
    vector<int> vec{1, 2, 3, 1};
    Solution s;

    int ret = s.rob(vec);
    std::cout << "ret = " << ret << std::endl;
    return 0;
}