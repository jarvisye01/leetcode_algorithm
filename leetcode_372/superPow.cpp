#include <iostream>
#include <vector>

using std::vector;

// 2 [1, 3] 

class Solution {
  const int limit = 1337;
public:
  int pow(int a, int p)
  {
    if (p == 0) return 1;

    int sum = 1;
    a %= limit;
    for (int i = 1; i <= p; i++)
    {
      sum *= a;
      sum %= limit;
    }

    return sum % limit;
  }
public:
  int superPow(int a, vector<int>& b) 
  {
    int sz = b.size(), sum = 1, pBase = a;

    for (int i = sz - 1; i >= 0; i--)
    {
      sum %= limit;
      sum *= pow(pBase, b[i]);
      pBase = pow(pBase, 10);
    }

    return sum % limit;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  int a = 2147483647;
  vector<int> vec{2, 0, 0};
  vector<int> vec1{2};
  for (int i = 0; i < 1000; i++) 
    vec1.push_back(0);
  std::cout << s.superPow(a, vec) << std::endl;
  std::cout << s.superPow(a, vec1) << std::endl;
  return 0;
}