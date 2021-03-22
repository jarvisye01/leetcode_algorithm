#include <iostream>
#include <unordered_map>

using std::unordered_map;

class Solution {
    int arr[3] = {2, 3, 5};

    bool isUglyAux(int num, unordered_map<int, bool>& m) {
        // std::cout << "num: " << num << std::endl;
        if (num == 1)  return true;
        auto iter = m.find(num);
        if (iter != m.end()) return iter->second;

        for (int x: arr) {
            if (num % x == 0 && isUglyAux(num / x, m)) return true;
        }
        m.insert(std::pair<int, bool>(num, false));
        return false;
    }
public:
    bool isUgly(int num) {
        if (num == 1) return true;
        if (num <= 0) return false;
        unordered_map<int, bool> m;
        return isUglyAux(num, m);
    }

    bool myIsUgly(int num) {
        if (num <= 0) return false;
        while (true) {
            if (num == 1) return true;
            if (num % 2 == 0) num /= 2;
            else if (num % 3 == 0) num /= 3;
            else if (num % 5 == 0) num /= 5;
            else return false;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 20; i++) {
        std::cout << i << " => " << s.isUgly(i) << std::endl;
    }
    return 0;
}