#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n > 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 1; i <= 100; i++) {
        std::cout << i << " => " << (s.isPowerOfThree(i) ? "true" : "false") << std::endl;
    }
    return 0;
}