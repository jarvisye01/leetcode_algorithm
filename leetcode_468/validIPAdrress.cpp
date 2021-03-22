#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

enum IpType { IPV4, IPV6, NEITHER };

class Solution 
{
  IpType getIpType(string IP)
  {
    int len = IP.length();
    if (len < 7 || len > 39)
      return NEITHER;
    for (int i = 0; i < len; i++)
    {
      if (IP[i] == '.')
        return IPV4;
      if (IP[i] == ':')
        return IPV6;
    }
    return NEITHER;
  }

  bool isDigit(char ch) 
  {
    return ch >= '0' && ch <= '9';
  }

  bool isHexLetters(char ch)
  {
    return isDigit(ch) || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
  }

  bool validIPV4(vector<string>& strs)
  {
    if (strs.size() != 4)
      return false;
    
    for (auto& str: strs)
    {
      int num = 0, len = str.length();
      if (len == 0)
        return false;
      if (str[0] == '0' && len != 1)
        return false;
      
      for (int i = 0; i < len; i++)
      {
        if (!isDigit(str[i]))
          return false;
        num = num * 10 + static_cast<int>(str[i] - '0');
      }
      if (num < 0 || num > 255)
        return false;
    }
    return true;
  }

  bool validIPV6(vector<string>& strs)
  {
    if (strs.size() != 8)
      return false;

    for (auto& str: strs)
    {
      int len = str.length();
      if (len == 0 || len > 4)
        return false;
      for (int i = 0; i < len; i++)
      {
        if (!(isDigit(str[i]) || isHexLetters(str[i])))
          return false;
      }
    }
    return true;
  }

  bool validIP(vector<string>& strs, IpType ipType) 
  {
    if (ipType == IPV4)
      return validIPV4(strs);
    else if (ipType == IPV6)
      return validIPV6(strs);
    return false;
  }
public:
  string validIPAddress(string IP) 
  {
    int len = IP.length();

    IpType ipType = getIpType(IP);
    if (ipType == NEITHER)
      return string("Neither");

    char split = ipType == IPV4 ? '.' : ':';

    int i = 0, last = 0;
    vector<string> strs;
    while (i < len)
    {
      while (i < len && IP[i] != split)
        i++;
      if (i == last)
        return string("Neither");
      strs.push_back(string(IP.begin() + last, IP.begin() + i));
      last = i = i + 1;
    }
    if (last == len)
      return string("Neither");

    // for (auto& s: strs)
    //   std::cout << s << std::endl;
    if (!validIP(strs, ipType))
      return string("Neither");
    return string(ipType == IPV4 ? "IPv4" : "IPv6");
  }
};

int main(int argc, char **argv) 
{
  Solution s;
  // string IP = "172.16.254.1";
  string IP = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
  auto ret = s.validIPAddress(IP);
  std::cout << ret << std::endl;
  return 0;
}