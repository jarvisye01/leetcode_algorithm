#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int first, last, sz;
        if ((sz = nums.size()) == 0) return ret;
        first = last = 0;
        while (last < sz) {
            while (last + 1 < sz && nums[last] == nums[last + 1] - 1) {
                last++;
            }
            ret.push_back(nums[first] == nums[last] ? std::to_string(nums[first]) : std::to_string(nums[first]) + "->" + std::to_string(nums[last]));
            first = ++last;
        }
        return ret;
    }
};

int main(int aegc, char **argv) {
    Solution s;
    vector<int> nums{1, 2, 3, 5, 6, 8};
    auto ret = s.summaryRanges(nums);
    std::cout << "size = " << ret.size() << std::endl;
    for (auto str: ret) {
        std::cout << str << std::endl;
    }
    return 0;
}