#include <iostream>

class Solution 
{
public:
  int findComplement(int num) 
  {
    uint32_t mask = 0, test = 1 << 31;
    while ((test & num) == 0)
    {
      mask |= test;
      test = test >> 1;
    }

    mask = ~mask;
    return (~num) & mask;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  for (int i = 1; i < 10; i++)
    printf("%d => %x\n", i, s.findComplement(i));
  return 0;
}