#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int sz = nums.size();
        set<int> s;
        vector<int> ret;
        for (int i = 0; i < sz; i++)
        {
            while (nums[i] - 1 != i)
            {
                if (nums[nums[i] - 1] == nums[i])
                    break;
                else 
                    std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] != i + 1)
                s.insert(i + 1);
        }

        return vector<int>(s.begin(), s.end());
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> nums{4,3,2,7,8,2,3,1};
    auto ret = s.findDisappearedNumbers(nums);
    for (auto x: ret)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}