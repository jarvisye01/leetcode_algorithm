#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int sz = nums.size(), limit = sz / 3;
        unordered_map<int, int> m;
        for (auto x: nums) {
            int count;
            unordered_map<int, int>::iterator iter = m.find(x);
            count = (iter == m.end() ? 1 : iter->second + 1);
            m[x] = count;
        }

        vector<int> ret;
        for (auto& p: m) {
            if (p.second > limit) ret.push_back(p.first);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> vec{1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> ret = s.majorityElement(vec);
    for (auto x: ret) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}