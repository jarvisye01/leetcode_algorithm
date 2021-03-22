#include <iostream>
#include <string>

using std::string;

class Solution
{
public:
  string addStrings(string num1, string num2) {
    int len1 = num1.length(), len2 = num2.length(), i = len1 - 1, j = len2 - 1;

    char ret[5200];
    int idx = 5200, carry = 0, tmp;
    while (i >= 0 && j >= 0)
    {
      tmp = carry + int(num1[i--] - '0') + int(num2[j--] - '0');
      carry = tmp / 10;
      ret[--idx] = char(tmp % 10 + '0');
    }

    while (i >= 0)
    {
      tmp = carry + int(num1[i--] - '0');
      carry = tmp / 10;
      ret[--idx] = char(tmp % 10 + '0');
    }

    while (j >= 0)
    {
      tmp = carry + int(num2[j--] - '0');
      carry = tmp / 10;
      ret[--idx] = char(tmp % 10 + '0');
    }

    if (carry || idx == 5200)
      ret[--idx] = char(carry + '0');

    return string(ret + idx, ret + 5200);
  }
};

int main(int argc, char **argv)
{
  Solution s;
  string s1 = "1231231", s2 = "23789423784";
  auto ret = s.addStrings(s1, s2);
  std::cout << ret << std::endl;
  return 0;
}
