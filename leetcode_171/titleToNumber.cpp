#include <iostream>

using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        int len, ret = 0;
        int64_t Base = 1;
        if ((len = s.length()) == 0) return ret;

        for (int i = len - 1; i >= 0; i--) {
            int num = int(s[i] - 'A') + 1;
            ret += Base * num;
            Base *= 26;
        }
        return ret;
    }
};


int main(int argc, char **argv) {
    Solution s;
    string str("AAZ");
    int ret = s.titleToNumber(str);
    std::cout << ret << std::endl;
    return 0;
}