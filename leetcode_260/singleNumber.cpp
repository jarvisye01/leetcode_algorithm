#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        unordered_set<int> set;
        int sz;
        
        if ((sz = nums.size()) == 0) return ret;

        for (int x: nums) {
            auto iter = set.find(x);
            if (iter == set.end()) set.insert(x); 
            else set.erase(iter);
        }

        if (set.size() == 2) {
            for (auto x: set) {
                ret.push_back(x);
            }
        }
        return ret;
    }

    vector<int> singleNumberBit(vector<int>& nums) {
        vector<int> ret;
        
        int64_t mask = 0;
        for (int x: nums) { mask ^= x; }

        int diff = mask & (-mask), res = 0;
        for (int x: nums) {
            if (x & diff) {
                res ^= x;
            }
        }
        ret.push_back(res);
        ret.push_back(res ^ mask);
        return ret;
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<int> vec{1, 2, 1, 3, 2, 5};
    vector<int> ret = s.singleNumber(vec);
    for (auto x: ret) {
        std::cout << x << " ";
    } 
    std::cout << std::endl;
    return 0; 
}