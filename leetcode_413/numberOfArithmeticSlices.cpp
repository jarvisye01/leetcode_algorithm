#include <iostream>
#include <vector>

using std::vector;

class Solution 
{
    int count(int N)
    {
        return ((N - 1) * (N - 2)) / 2;
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int sz, idx = 0, ret = 0;
        if ((sz = nums.size()) < 3)
            return 0;

        while (idx < sz - 1)
        {
            int dis = nums[idx + 1] - nums[idx], start = idx, end;
            idx++;

            while (idx < sz - 1 && (nums[idx + 1] - nums[idx] == dis))
                idx++;

            end = idx;
            ret += count(end - start + 1);
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    vector<int> nums{1, 2, 3, 4, 5, 6};
    Solution s;
    auto ret = s.numberOfArithmeticSlices(nums);
    std::cout << ret << std::endl;
    return 0;
}