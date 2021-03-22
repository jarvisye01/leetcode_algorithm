#include <iostream>
#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int idx = 0, i = 0, j = 0, plen = pattern.length(), slen = s.length();
        unordered_map<char, string> map;
        unordered_map<string, char> map1;

        while (idx < plen && j < slen) {
            // std::cout << "idx = " << idx << std::endl;
            while (j < slen && s[j] != ' ') 
                j++;
            // std::cout << "[" << i << ", " << j << ")" << std::endl;
            string ts = s.substr(i, j - i);
            // std::cout << ts << std::endl;
            auto iter = map.find(pattern[idx]);
            auto iter1 = map1.find(ts);

            if (iter == map.end() && iter1 == map1.end()) {
                map.insert(std::make_pair(pattern[idx], ts));
                map1.insert(std::make_pair(ts, pattern[idx]));
            } else if (iter != map.end() && iter1 != map1.end()) {
                if (iter->second != ts || iter1->second != pattern[idx])
                    return false;
            } else return false;

            while (j < slen && s[j] == ' ')
                j++;
            i = j;
            idx++;
        }
        if (idx < plen || j < slen) return false;
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    string pattern = "abba";
    string str = "dog cat cat dog";
    std::cout << (s.wordPattern(pattern, str) ? "true" : "false") << std::endl;
    return 0;
}