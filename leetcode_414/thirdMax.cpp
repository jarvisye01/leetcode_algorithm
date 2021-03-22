#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution 
{
public:
    int thirdMax(vector<int>& nums) 
    {
        int sz = nums.size();
        
        int32_t m = nums[0], top = nums[0], last_top = top, max, min;
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] < m)
                m = nums[i];
            if (nums[i] > top)
                top = nums[i];
        }
        max = top;
        min = m;

        for (int i = 0; i < 2; i++)
        {
            int32_t last_top = top;
            for (int x: nums) 
            {
                if (x > m && x < top)
                    m = x;
            }
            top = m;
            m = min;
            if (top == last_top)
                return max;
        }

        return top;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> nums{2, 2, 3, 1};
    auto ret = s.thirdMax(nums);
    std::cout << ret << std::endl;
    return 0;
}