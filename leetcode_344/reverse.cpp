#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) std::swap(s[i++], s[j--]);
    }
};

int main(int argc, char **argv) {
    vector<char> str{'a', 'b', 'c', 'd', 'e'};
    Solution s;

    std::cout << "before: ";
    for (auto x: str) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    s.reverseString(str);
    std::cout << "after: ";
    for (auto x: str) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}