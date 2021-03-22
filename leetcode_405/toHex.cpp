#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution 
{
public:
    string toHex(int num) 
    {
        char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        if (num == 0)
            return "0";

        uint32_t tnum = num;

        vector<int> vec;
        while (tnum != 0) 
        {
            vec.push_back(tnum % 16);
            tnum /= 16;
        }

        int sz = vec.size();
        string str(sz, 0);
        for (int i = sz - 1; i >= 0; i--)
            str[sz - 1 - i] = arr[vec[i]];

        return str;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    auto str = s.toHex(-1);
    std::cout << str << std::endl;
    return 0;
}