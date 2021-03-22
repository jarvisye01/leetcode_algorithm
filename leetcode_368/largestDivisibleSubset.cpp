#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::deque;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();

        if (len == 0) 
            return vector<int>();

        std::sort(nums.begin(), nums.end());

        vector<int> ret(len, 1);
        int max_idx = 0;
        ret[0] = 1;

        for (int i = 1; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0)
                    ret[i] = std::max(ret[i], ret[j] + 1);
            }
            max_idx = ret[i] > ret[max_idx] ? i : max_idx;
        }

        // for (auto x: ret)
        //     std::cout << x << " ";
        // std::cout << std::endl;

        deque<int> q;
        int find = ret[max_idx];
        for (int i = max_idx; i >= 0; i--) {
            if (q.size() == 0 || (find == ret[i] && q.front() % nums[i] == 0)) {
                q.push_front(nums[i]);
                find--;
            }
        }

        return vector<int>(q.begin(), q.end());
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums{2, 3, 8, 9, 27};
    auto ret = s.largestDivisibleSubset(nums);

    for (auto x: ret) 
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}