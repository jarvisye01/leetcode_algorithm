#include <iostream>

class Solution {
    int getN(int n) {
        n = n > 10 ? 10 : n;

        if (n == 1) return 9;
        int ret = 9;
        for (int i = 1; i < n; i++) 
            ret *= (10 - i);
        
        return ret;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        n = n > 10 ? 10 : n;

        if (n == 0) return 1;
        int last = 1;

        for (int i = 1; i <= n; i++) {
            last += getN(i);
        }

        return last;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 100; i++) 
        std::cout << i << " => " << s.countNumbersWithUniqueDigits(i) << std::endl;
    std::cout << std::endl;
    return 0;
}