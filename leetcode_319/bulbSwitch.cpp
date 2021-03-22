#include <iostream>

class Solution {
public:
    int bulbSwitch(int n) {
        int ret = 0, num = 1;
        while (num <= n / num) {
            ret++;
            num++;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 1; i < 101; i++) 
        std::cout << i << " => " << s.bulbSwitch(i) << std::endl;
    return 0;
}