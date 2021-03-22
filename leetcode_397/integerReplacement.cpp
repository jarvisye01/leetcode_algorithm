#include <iostream>
#include <map>

using std::map;

class Solution {
public:
    int64_t aux(int64_t n, map<int, int>& m) {
        auto iter = m.find(n);
        if (iter != m.end()) 
            return iter->second;
        // i => i - 1, (i + 1) / 2
        int ret;
        if (n == 1) 
            ret = 0;
        else if (n % 2 == 0)
            ret = aux(n / 2, m) + 1;
        else 
            ret = std::min(aux(n - 1, m), aux(n + 1, m)) + 1;

        m.insert(std::pair<int, int>(n, ret));

        return ret;
    }

    int integerReplacement(int n) {
        map<int, int> m;
        return static_cast<int>(aux(n, m));
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 1; i < 101; i++)
        std::cout << i << " => " << s.integerReplacement(i) << std::endl;
    return 0;
}