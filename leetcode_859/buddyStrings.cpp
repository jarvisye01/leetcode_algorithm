#include <iostream>
#include <string>
#include <set>

using std::string;
using std::set;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int len = A.length();
        if (len != B.length() || len == 0) return false;

        int diff[2], count = 0;
        set<int> letters;
        for (int i = 0; i < len; i++) {
            if (A[i] != B[i]) {
                if (count > 1) 
                    return false;
                diff[count++] = i;
            }
            letters.insert(A[i]);
        }

        return (count == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]) || (count == 0 && letters.size() < len);
    }
};

int main(int argc, char **argv) {
    string s1 = "aaaaaaabc", s2 = "aaaaaaacb";
    Solution s;
    auto ret = s.buddyStrings(s1, s2);
    std::cout << (ret ? "buddy" : "no buddy") << std::endl;
    return 0;
}