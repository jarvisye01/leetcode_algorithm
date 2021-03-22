#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int getNthDigit(int num, int n) {
        vector<int> vec;
        int bits = 0;
        while (num > 0) {
            vec.push_back(num % 10);
            num /= 10;
            bits++;
        }

        return vec[bits - n];
    }

    int findNthDigitAux(int n) {
        if (n < 10) 
            return n;

        int64_t i = 10, N = n, bits = 2, count = 90, start = 10;
        while (i + count * bits <= N) {
            i += count * bits;
            count *= 10;
            start *= 10;
            bits++;
        }
        
        while (i + bits <= N) {
            i += bits;
            start++;
        }

        return getNthDigit(start, N - i + 1);
    }
public:
    int findNthDigit(int n) {
        return  findNthDigitAux(n);
    }
};

int main(int argc, char **argv) {
    int num = 12345;
    Solution s;
    for (int i = 1; i < 6; i++)
        std::cout << s.getNthDigit(num, i) << std::endl;

    for (int i = 0; i < 101; i++)
        std::cout << i << " => " << s.findNthDigit(i) << std::endl;
    
    return 0;
}