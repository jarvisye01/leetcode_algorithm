#include <iostream>

const int target = 6;

int guess(int num) {
    if (num == target) return 0;
    if (num < target) return -1;
    return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n;
        while (i <= j) {
            int mid = i + (j - i) / 2, g;
            g = guess(mid);
            if (g == 0) return mid;
            else if (g == -1) i = mid + 1;
            else j = mid - 1;
        }
        return -1;
    }
};

int main(int agrc, char **argv) {
    Solution s;
    int ret = s.guessNumber(10);
    std::cout << "ret = " << ret << std::endl;
    return 0;
}