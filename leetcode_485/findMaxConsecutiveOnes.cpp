#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int len, start, i = 0, maxOnes = 0;
    if ((len = nums.size()) == 0)
      return 0;

    while (i < len)
    {
      while (i < len && nums[i] != 1)
        i++;
      start = i;
      while (i < len && nums[i] == 1)
       i++;

      if (start < len)
        maxOnes = std::max(i - start, maxOnes);
    }

    return maxOnes;
  }
};

int main(int argc, char **argv) 
{
  Solution s;
  vector<int> nums = {1, 1, 0, 1, 1, 1, 0};
  auto ret = s.findMaxConsecutiveOnes(nums);
  std::cout << ret << std::endl;
  return 0;
}