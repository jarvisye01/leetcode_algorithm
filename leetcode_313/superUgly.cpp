#include <iostream>
#include <vector>

using std::vector;

class Solution {
    int getMin(vector<int>& ret, vector<int>& ptr, vector<int>& primes) {
        int min = INT32_MAX, sz = ptr.size();

        for (int i = 0; i < sz; i++) {
            int t = 0;
            if ((t = ret[ptr[i]] * primes[i]) < min) min = t;
        }

        return min;
    }
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        vector<int> ret;
        ret.push_back(1);

        vector<int> ptr(primes.size(), 0);
        for (int i = 0; i < n; i++) {
            int ugly = getMin(ret, ptr, primes);
            for (int k = 0; k < sz; k++) {
                if (ret[ptr[k]] * primes[k] == ugly) {
                    ptr[k]++;
                }
            }
            ret.push_back(ugly);
        }
        return ret[n - 1];
    }
};

int main(int argc, char **argv) {
    vector<int> primes{2, 7, 13, 19};

    Solution s;
    for (int i = 1; i <= 100; i++) {
        std::cout << i << " => " << s.nthSuperUglyNumber(i, primes) << std::endl;    
    }
    return 0;
}