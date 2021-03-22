#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
    bool isPrefixMatch(const string& str, const string& pre) {
        int len1, len2;
        if ((len1 = str.length()) < (len2 = pre.length())) return false;
        for (int i = 0; i < len2; i++) {
            if (pre[i] != str[i]) return false;
        }
        return true;
    }

    bool wordBreakAux(const string& s, int idx, vector<string>& wordDict, vector<int>& set) {
        if (idx > s.length()) return false;
        if (idx == s.length()) return true;

        string tmp(s.begin() + idx, s.end());
        for (const string& ts: wordDict) {
            if (isPrefixMatch(tmp, ts) && set[idx]) {
                if (wordBreakAux(s, idx + ts.length(), wordDict, set)) return true;
            }
        }
        set[idx] = 0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> set(s.length(), 1);
        return wordBreakAux(s, 0, wordDict, set);
    }
};

int main(int agrc, char **argv) {
    Solution s;
    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> dict{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    std::cout << (s.wordBreak(str, dict) ? "true" : "false") << std::endl;
    return 0;
}