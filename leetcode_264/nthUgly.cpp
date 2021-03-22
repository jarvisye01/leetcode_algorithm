#include <iostream>
#include <vector>

using std::vector;

class Solution {
    vector<int> vec;
public:
    Solution() {
        vec.push_back(1);
        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i <= 1690; i++) {
            int ugly = std::min(vec[i2] * 2, std::min(vec[i3] * 3, vec[i5] * 5));
            vec.push_back(ugly);
            if (ugly == vec[i2] * 2) 
                i2 += 1;
            if (ugly == vec[i3] * 3)
                i3 += 1;
            if (ugly == vec[i5] * 5) 
                i5 += 1;
        }
    }

    int nthUglyNumber(int n) {
        return vec[n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 1; i < 1690; i++) {
        std::cout << i << " => " << s.nthUglyNumber(i) << std::endl;
    }
    return 0;
}