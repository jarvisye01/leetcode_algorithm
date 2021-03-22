#include <iostream>

using std::string;

class Solution 
{
    bool validString(const string& s, int i, int j)
    {
        int len = s.length(), cmp = i, dis = j - i + 1;

        for (int k = j + 1; k < len; k++)
        {
            if (s[k] != s[cmp])
                return false;
            cmp = (cmp - i + 1) % dis + i;
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string s) 
    {
        int len = s.length();
        if (len < 2) return false;

        for (int i = 2; i <= len; i++) 
        {
            if (len % i == 0)
            {
                int N = len / i;
                if (validString(s, 0, N - 1))
                    return true;
            }
        }

        return false;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string str = "abccabccabccd";
    auto ret = s.repeatedSubstringPattern(str);
    std::cout << (ret ? "true" : "false") << std::endl;
    return 0;
}