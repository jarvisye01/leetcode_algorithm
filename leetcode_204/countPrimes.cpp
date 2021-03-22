#include <iostream>

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;

        int *arr = new int[n];
        int ret = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = 1;
        }

        for (uint64_t i = 2; i < n; i++) {
            if (arr[i]) {
                ret++;
                if (i * i < n) {
                    for (int k = i * i; k < n; k += i) {
                        arr[k] = 0;
                    }
                }
            }
        }
        delete [] arr;
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 100; i++) {
        std::cout << i << " => " << s.countPrimes(i) << std::endl;
    }
    int test = 100000;
    std::cout << test << " => " << s.countPrimes(test) << std::endl;
    return 0;
}