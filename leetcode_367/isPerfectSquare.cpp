#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        else if (num == 0 || num == 1) return true;

        int low = 1, high = num / 2, mid = -1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mid == num / mid && num % mid == 0) return true;
            else if (mid > num / mid) high = mid - 1;
            else low = mid + 1;
        }

        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 101; i++) {
        std::cout << i << " => ";
        std::cout << (s.isPerfectSquare(i) ? "true" : "false") << std::endl;
    }
    return 0;
}