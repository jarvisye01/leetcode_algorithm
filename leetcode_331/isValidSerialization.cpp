#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
  bool isDigit(char ch)
  { return ch >= '0' && ch <= '9'; }
public:
  bool isValidSerialization(string preorder) 
  {
    int len = preorder.length(), i = 0;
    if (len == 0) return true;

    // 0 => #
    // 1 => number
    stack<int> s1;
    stack<int> s2;

    while (i < len)
    {
      // process space
      while (i < len && preorder[i] == ' ')
        i++;
      if (i >= len) 
        break;
      
      if (preorder[i] == ',')
        i++;
      else if (preorder[i] == '#')
      {
        // process #
        i++;
        s2.push(0);
      }
      else if (isDigit(preorder[i]))
      {
        while (isDigit(preorder[i]))
          i++;
        s2.push(1);
      }
    }

    while (s2.size() > 0)
    {
      int e = s2.top();
      if (e == 0)
      {
        s2.pop();
        s1.push(e);
      } 
      else 
      {
        if (s1.size() >= 2)
        {
          // pop 2 nodes[left, right]
          s1.pop();
          s1.pop();
          s2.pop();
          // push root into s1
          s1.push(e);
        }
        else
        { return false; }
      }
    }

    if (s2.size() == 0 && s1.size() == 1)
    { return true; }

    return false;
  }
};

int main(int argc, char **argv) {
  Solution s;
  string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  bool ret = s.isValidSerialization(str);
  std::cout << "ret = " << ret << std::endl;
  return 0;
}