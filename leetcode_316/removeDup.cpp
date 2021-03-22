#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.length();
        vector<int> isVisit(26), letterNum(26);
        for (char c: s) 
            letterNum[c - 'a']++;

        string stack;
        for (char c: s) {
            if (!isVisit[c - 'a']) {
                while (!stack.empty() && stack.back() > c) {
                    if (letterNum[stack.back() - 'a'] > 0) {
                        isVisit[stack.back() - 'a'] = 0;
                        stack.pop_back();
                    } else {
                        break;
                    }
                }
                isVisit[c - 'a'] = 1;
                stack.push_back(c);
            }
            letterNum[c - 'a']--;
        }
        return stack;
    }
};

int main(int argc, char **argv) {
    Solution s;
    string str = "cbacdcbc";
    string ret = s.removeDuplicateLetters(str);
    std::cout << ret << std::endl;
}