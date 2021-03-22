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

    void wordBreakAux(const string& s, int idx, vector<string>& wordDict, vector<int>& set, vector<string>&& path, vector<string>& ret) {
        if (idx > s.length()) return;
        if (idx == s.length()) {
            string tmp = "";
            int len = path.size();
            for (int i = 0; i < len; i++) {
                if (i < len - 1) tmp += path[i] + " ";
                else tmp += path[i];
            }
            ret.push_back(tmp);
            return;
        }

        int last = ret.size();
        string tmp(s.begin() + idx, s.end());
        for (const string& ts: wordDict) {
            if (isPrefixMatch(tmp, ts) && set[idx]) {
                path.push_back(ts);
                wordBreakAux(s, idx + ts.length(), wordDict, set, std::move(path), ret);
                path.pop_back();
            }
        }
        if (ret.size() == last) set[idx] = 0;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        vector<int> set(s.length(), 1);
        wordBreakAux(s, 0, wordDict, set, vector<string>(), ret);
        return ret;
    }
};

int main(int agrc, char **argv) {
    Solution s;
    string str = "aaaaaaaaaaaaaa";
    vector<string> dict{"a", "aa", "aaa"};
    vector<string> ret = s.wordBreak(str, dict);
    for (auto ts: ret) {
        std::cout << ts << std::endl;
    }
    return 0;
}