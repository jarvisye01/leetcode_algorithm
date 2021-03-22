#include <iostream>
#include <string>
#include <stack>
#include <vector>

using std::string;
using std::stack;
using std::vector;


class Solution {
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    bool isLetter(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

public:
    string decodeString(string s) {
        int len;
        if ((len = s.length()) == 0) 
            return "";

        stack<char> stk;
        stack<int> digit;

        for (int i = 0; i < len; i++) {
            // [ or letter or digit
            if (s[i] == '[' || isLetter(s[i])) {
                stk.push(s[i]);
                continue;
            } else if (isDigit(s[i])) {
                int num = 0;
                while (isDigit(s[i])) {
                    num = num * 10 + static_cast<int>(s[i] - '0');
                    i++;
                }
                digit.push(num);
                // * reperesent a number
                stk.push('*');
                // balance for (......; i++)
                i--;
                continue;
            }

            // ]
            vector<char> vec;
            int count = 1;
            while (stk.top() != '[') {
                vec.push_back(stk.top());
                stk.pop();
            }
            // pop [
            stk.pop();
            if (stk.size() > 0 && stk.top() == '*') {
                count = digit.top();
                digit.pop();
                // pop digit
                stk.pop();
            }

            for (int j = 0; j < count; j++) {
                for (auto iter = vec.rbegin(); iter != vec.rend(); iter++)
                    stk.push(*iter);
            }
        }

        string ret(stk.size(), '0');
        for (int i = stk.size() - 1; i >= 0; i--) {
            ret[i] = stk.top();
            stk.pop();
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    string str = "100[leetcode]";
    string ret = s.decodeString(str);
    std::cout << ret << std::endl;
    return 0;
}