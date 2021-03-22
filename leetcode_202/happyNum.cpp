#include <iostream>
#include <set>

using std::set;

class Solution {
    int get_pow_sum(int n) {
        if (n == 0) return 0;
        int ret = 0;
        while (n > 0) {
            int t = n % 10;
            n /= 10;
            ret += t * t;
        }
        return ret;
    }
public:
    bool isHappy(int n) {
        set<int> s;
        for (;;) {
            int tnum = get_pow_sum(n);
            if (tnum == 1) return true;
            if (s.find(tnum) != s.end()) return false;
            s.insert(tnum);
            n = tnum;
        } 
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 30; i++) {
        std::cout << i << " => " << (s.isHappy(i) ? "true" : "false") << std::endl;
    }
    return 0;
}