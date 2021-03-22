#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;
using std::set;

class Solution 
{
    bool canMutation(string& s1, string& s2)
    {
        if (s1.length() != s2.length())
            return false;
        int diff = 0, len = s1.length();

        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
                diff++;
            if (diff > 1)
                return false;
        }

        return diff == 1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int sz = bank.size();
        if (sz == 0) 
            return -1;
    
        // get index of end in bank
        int endIdx = -1;
        for (int i = 0; i < sz; i++)
        {
            if (end.compare(bank[i]) == 0) 
            {
                endIdx = i;
                break;
            }
        }
        if (endIdx == -1)
            return -1;

        set<int> visited;
        visited.insert(endIdx);
        vector<int> leaf;
        leaf.push_back(endIdx);
        int ret = 1;
        while (leaf.size() != 0)
        {
            vector<int> newLeaf;
            for (int idx: leaf)
            {
                if (canMutation(bank[idx], start))
                    return ret;

                for (int i = 0; i < sz; i++)
                {
                    if (visited.find(i) != visited.end())
                        continue;
                    
                    for (int v: leaf)
                    {
                        if (canMutation(bank[v], bank[i]))
                        {
                            newLeaf.push_back(i);
                            visited.insert(i);
                        }
                    }
                }

            }
            leaf.clear();
            leaf.assign(newLeaf.begin(), newLeaf.end());
            ret++;
        }

        return -1;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string s1 = "AAAACCCC", s2 = "CCCCCCCC";
    vector<string> bank{"AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC"};
    auto ret = s.minMutation(s1, s2, bank);
    std::cout << ret << std::endl;
    return 0;
}