#include <iostream>
#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length();
        if (j-- < 2) return s;

        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (i < j) {
            while (i < j && set.find(s[i]) == set.end()) { i++; }
            while (i < j && set.find(s[j]) == set.end()) { j--; }

            if (i < j) 
                std::swap(s[i++], s[j--]);
        }

        return s;
    }
};

int main(int argc, char **argv) {
    Solution s;
    string vec[] = {"hello", "leetcode", "world"};
    for (int i = 0; i < 3; i++) {
        std::cout << vec[i] << " => ";
        std::cout << s.reverseVowels(vec[i]) << std::endl;
    }
    return 0;
}