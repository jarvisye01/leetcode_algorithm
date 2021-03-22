#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int len, left = 0, right = 0;
        vector<string> ret;
        vector<int> errRight;

        auto iter = std::find(s.begin(), s.end(), '(');
        string ts(iter, s.end());
        len = ts.length();
        
        for (int i = 0; i < len; i++) {
            if (s[i] == '(')
                left++;
            else if (s[i] == ')') {
                right++;
                if (right > left)
                    errRight.push_back(i);
            }
        }

        if (right > left) {

        } else if (right == left) {

        } else {

        }
    }
};

int main(int argc, char **argv) {
    return 0;
}