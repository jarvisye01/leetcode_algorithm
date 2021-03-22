#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.length(), len2 = t.length(), i = 0, j = 0;
        if (len1 > len2) return false;
        if (len1 == 0) return true;

        while (j < len2) {
            if (s[i] == t[j++])
                i++;
            if (i == len1) return true;
        }

        return false;
    }
};

int main(int argc, char **argv) {
    Solution sl;
    string s = "abc", t = "ahbgdc";
    std::cout << s << (sl.isSubsequence(s, t) ? " is " : " is not ") << "subsequence of " << t << std::endl;
    return 0;
}