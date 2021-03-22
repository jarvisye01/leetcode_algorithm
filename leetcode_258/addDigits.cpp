#include <iostream>

class Solution {
public:
    // 38
    // 3 + 8 = 11   1 + 1 = 2
    int addDigits(int num) {
        int ret = 0;
        while (num > 0) {
            int t = num % 10;
            num /= 10;
            if (ret + t > 9) {
                ret = (ret + t) % 10 + 1;
            } else {
                ret += t;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 100; i++) {
        std::cout << i << " => " << s.addDigits(i) << std::endl;
    }
    return 0;
}