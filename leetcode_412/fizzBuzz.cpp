#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution
{
public:
  vector<string> fizzBuzz(int n)
  {
    vector<string> ret;
    for (int i = 1; i <= n; i++)
    {
      string tmp;
      if (i % 3 == 0)
        tmp += "Fizz";
      if (i % 5 == 0)
        tmp += "Buzz";
      ret.push_back(tmp.length() > 0 ? tmp : std::to_string(i));
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  auto ret = s.fizzBuzz(30);
  for (auto& str: ret)
    std::cout << str << std::endl;
  return 0;
}