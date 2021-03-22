#include <iostream>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len;

        if (s.length() != t.length()) return false;
        if ((len = s.length()) == 0) return true;

        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                m1[s[i]] = i;
                m2[t[i]] = i;
                continue;
            }
            if ((m1.find(s[i]) == m1.end()) != (m2.find(t[i]) == m2.end())) return false;
            if ((m1.find(s[i]) != m1.end()) && ((*m1.find(s[i])).second != (*m2.find(t[i])).second)) return false;
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string s("paper"), t("title");
    bool ret = solution.isIsomorphic(s, t);
    std::cout << (ret ? "true" : "false") << std::endl;
    return 0;
}