#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        uint64_t num = 1;
        while (num < n) {
            num *= 2;
        }
        if (num == n) return true;
        if (num > n) return false;
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 100; i++) {
        std::cout << i << " => " << (s.isPowerOfTwo(i) ? "true" : "false") << std::endl;
    }
    return 0;
}