#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size(), total = 1;
        vector<int> ret(sz);
        int left = 1, right = 1;
        for (int i = sz - 1; i >= 0; i--) {
            total *= nums[i];
            ret[i] = total;
        }

        for (int i = 0; i < sz; i++) {
            if (i == sz - 1) right = 1;
            else right = ret[i + 1];
            ret[i] = left * right;
            left *= nums[i];
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    vector<int> nums{1, 2, 3, 4, 5};
    Solution s;
    vector<int> ret = s.productExceptSelf(nums);
    for (auto x: ret) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}