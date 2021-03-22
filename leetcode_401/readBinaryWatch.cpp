#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

using std::vector;
using std::string;

int arr[6] = {1, 2, 4, 8, 16, 32};
enum style { HOUR, MIN };

class Solution 
{
    void getNums(int cur, int lastIdx, int total, int target, vector<int>& set, vector<int>& ret, style stype) 
    {
        if (cur == target) 
        {
            if (stype == HOUR) 
            {
                if (total >= 0 && total <= 11) 
                    ret.push_back(total);
            } 
            else if (stype == MIN) 
            {
                if (total >= 0 && total <= 59) 
                    ret.push_back(total);
            } 
            return;
        }

        int limit = stype == HOUR ? 4 : 6;
        for (int i = lastIdx; i < limit; i++) 
        {
            if (set[i])
                continue;
            set[i] = 1;
            getNums(cur + 1, i + 1, total + arr[i], target, set, ret, stype);
            set[i] = 0;
        }
    }
public:
    vector<string> readBinaryWatch(int num) 
    {
        vector<string> ret;
        vector<int> hours, mins;
        vector<string> format = {"%d:0%d", "%d:%d"};
        for (int i = 0; i <= 3 && num - i >= 0; i++) 
        {
            hours.clear();
            mins.clear();
            vector<int> set(6, 0);
            getNums(0, 0, 0, i, set, hours, HOUR);
            getNums(0, 0, 0, num - i, set, mins, MIN);

            for (auto h: hours) 
            {
                for (auto m: mins)
                {
                    char buf[6];
                    int n = sprintf(buf, m < 10 ? format[0].c_str() : format[1].c_str(), h, m);
                    ret.push_back(string(buf));
                }
            }
        }

        return ret;
    }
};

int main(int argc, char **argv) 
{
    Solution s;
    auto ret = s.readBinaryWatch(5);
    for (auto& str: ret) 
        std::cout << str << std::endl;
    
    return 0;
}