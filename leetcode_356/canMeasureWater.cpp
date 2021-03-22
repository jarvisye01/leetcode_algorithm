#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x > y) std::swap(x, y);
        if (z > x + y) return false;
        if (x == 0) return z == x || z == y;
        int ty = y, mod = 1;
        while (mod != 0) {
            mod = ty % x;
            if ((ty - z) % x == 0 || (2 * ty - z) % x == 0) return true;
            ty = y - (x - mod);
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> vec = {{35, 4, 6}, {1, 2, 3}, {4, 6, 3}};
    for (auto& v: vec) {
        std::cout << (s.canMeasureWater(v[0], v[1], v[2]) ? "true" : "false") << std::endl;
    }
    return 0;
}