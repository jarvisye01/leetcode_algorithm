#include <iostream>
#include <string>
#include <deque>

using std::string;
using std::deque;

class Solution 
{
    string trimZero(string str)
    {
        int i = 0, len = str.length();
        for (; i < len; i++)
            if (str[i] != '0')
                break;
        
        if (i == len)
            return "0";
        return str.substr(i, len - i);
    }
public:
    string removeKdigits(string num, int k) 
    {
        int len, i = 0, del = 0;
        if ((len = num.length()) <= k) return "0";
        
        deque<char> deq;
        
        while (i < len)
        {
            while (deq.size() > 0 && num[i] < deq.back())
            {
                deq.pop_back();
                del++;
                if (del == k)
                    return trimZero(string(deq.begin(), deq.end()) + num.substr(i, len - i));
            }
            deq.push_back(num[i]);
            i++;
        }

        return trimZero(string(deq.begin(), deq.begin() + len - k));
    }
};

int main(int argc, char **argv)
{
    Solution s;
    auto ret = s.removeKdigits("10200", 1);
    std::cout << ret << std::endl;
    return 0;
}