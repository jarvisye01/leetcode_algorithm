#include <iostream>

class Solution {
public:
    // int getSum(int a, int b) {
    //     return a + b;
    // }

    int getSum(int a, int b) {
        unsigned ua = a, ub = b;
        while (ub != 0) {
            unsigned tmp = ua ^ ub;
            ub = (ua & ub) << 1;
            ua = tmp;
        }

        return static_cast<int>(ua);
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::cout << "1 + 2 = " << s.getSum(1, 2) << std::endl;
    std::cout << "-1 + 2 = " << s.getSum(-1, 2) << std::endl;
    std::cout << "101 + 1098 = " << s.getSum(101, 1098) << std::endl;
    return 0;
}