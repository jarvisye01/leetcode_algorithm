#include <iostream>

class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 == 0) return false;
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 1; i <= 100; i++) {
        std::cout << i << " => " << (s.canWinNim(i) == 1 ? "true" : "false") << std::endl;
    }
    return 0;
}