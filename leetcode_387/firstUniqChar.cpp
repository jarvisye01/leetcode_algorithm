#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    int firstUniqChar(string s) {
        int i = 0, j = 0, len = s.length();
        map<char, int> m;

        while (j < len) {
            m[s[j]]++;
            while (i <= j && m[s[i]] != 1)
                i++;
            j++;
        }

        return i < len ? i : -1;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::string str("loveleetcode");
    int ret = s.firstUniqChar(str);
    std::cout << "ret = " << ret << std::endl;
    return 0;
}