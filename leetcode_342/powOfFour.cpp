#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n != 1) {
            if (n % 4 != 0) return false;
            n /= 4;
        }
        return true;
    }

    bool isPowOfFour(int n) {
        if (n <= 0) return false;
        if ((n & (n - 1)) != 0) return false;
        if ((n & 0x55555555) == n) return true;
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 100; i++) {
        std::cout << i << " => " << (s.isPowerOfFour(i) ? "true" : "false") << std::endl;
    }
    return 0;
}