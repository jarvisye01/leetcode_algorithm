#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> m1, m2;
        for (char ch: s) 
            m1[ch]++;
        for (char ch: t) 
            m2[ch]++;

        for (auto& p: m2) {
            if (p.second != m1[p.first]) 
                return p.first;
        }

        return '0';
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string s = "abcd", t = "abcde";
    auto ch = solution.findTheDifference(s, t);
    std::cout << ch << std::endl;
    return 0;
}