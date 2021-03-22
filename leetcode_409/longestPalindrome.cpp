#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;

class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        int ret = 0;
        map<char, int> m;
        for (char ch: s)
            m[ch]++;
        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            ret += (iter->second / 2) * 2;
        }
        return ret < s.length() ? ret + 1 : ret;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string str = "akhsdkasiuqwqiweuoasda";
    auto ret = s.longestPalindrome(str);
    std::cout << ret << std::endl;
}