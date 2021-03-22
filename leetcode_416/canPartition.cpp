#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
public:
  bool canPartition(vector<int>& nums)
  {
    int ret = 0, target;
    for (int x: nums)
      ret += x;
    if (ret % 2)
      return false;

    target = ret / 2;
    vector<bool> arr(target + 1, false);
    arr[0] = true;

    for (int i = 1; i < nums.size(); i++)
    {
      for (int j = target; j >= nums[i - 1]; j--)
        arr[j] = arr[j] || arr[j - nums[i - 1]];
    }
    return arr[target];
  }
};

int main(int argc, char **argv)
{
  vector<int> nums{1, 15, 7, 5};
  Solution s;
  auto ret = s.canPartition(nums);
  std::cout << (ret ? "true" : "false") << std::endl;
  return 0;
}