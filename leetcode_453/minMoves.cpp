#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  int minMoves(vector<int>& nums)
  {
    int sz = nums.size();
    if (sz < 2) return 0;

    std::sort(nums.begin(), nums.end());
    int i = sz - 1, ret = 0, d = 0, num1, num2, total = 0;
    num1 = nums[i];
    while (i >= 0) 
    {
      int j = i, t;
      while (i > 0 && nums[i] == nums[i - 1])
        i--;

      num2 = nums[i] + ret;
      int t1 = d * (num1 - num2);
      ret += t1;
      num1 = t1 + num2;
      d += j - i + 1;
      i--;
    }
    return ret;
  }

  int minMovesII(vector<int>& nums)
  {
    auto iter = std::min_element(nums.begin(), nums.end());
    int m = *iter, sz = nums.size(), ret = 0;
    for (int i = 0; i < sz; i++)
      ret += nums[i] - m;

    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<int> nums{1, 3, 5, 7, 11};
  auto ret = s.minMoves(nums);
  std::cout << ret << std::endl;
}