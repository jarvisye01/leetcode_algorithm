#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int bit = 0; bit < 32; bit++) {
            if ((1 << bit) & n) 
                ret++;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    uint32_t num = 10;   // 1010
    int ret = s.hammingWeight(num);
    std:: cout << ret << std::endl;
    return 0;
}