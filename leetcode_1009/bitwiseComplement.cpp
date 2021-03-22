#include <iostream>

class Solution {
public:
  int bitwiseComplement(int N) 
  {
  if (N == 0)
      return 1;
  uint32_t mask = 0, test = 1 << 31;
  while ((test & N) == 0)
  {
    mask |= test;
    test = test >> 1;
  }

  mask = ~mask;
  return (~N) & mask;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  for (int i = 0; i < 10; i++)
    printf("%d => %d\n", i, s.bitwiseComplement(i));
  return 0;
}