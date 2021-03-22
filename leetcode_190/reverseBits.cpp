#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; i++) {
            if ((1 << (31 - i)) & n) ret |= 1 << i;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    uint32_t num = 10;
    uint32_t ret = s.reverseBits(num);
    std::cout << ret << std::endl;
    return 0;
}