#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int i = g.size() - 1, j = s.size() - 1, ret = 0;
        while (i >= 0 && j >= 0)
        {
            if (s[j] >= g[i]) {
                ret++;
                i--;
                j--;
            }
            else
            {
                i--;
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> g{1, 2, 3}, s{1, 2};
    auto ret = sl.findContentChildren(g, s);
    std::cout << ret << std::endl;
    return 0;
}