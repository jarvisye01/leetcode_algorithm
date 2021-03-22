#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        uint32_t ret = UINT32_MAX;
        for (uint32_t i = m; i <= n; i++) {
            ret &= i;
            if (ret == 0) break;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    uint32_t ret = s.rangeBitwiseAnd(5, 7);
    std::cout << ret << std::endl;
    return 0;
}