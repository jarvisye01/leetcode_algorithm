#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (auto x: nums) {
            if (s.find(x) != s.end()) return true;
            s.insert(x);
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5, 2};
    std::cout << (s.containsDuplicate(nums) ? "true" : "false") << std::endl;
    return 0;
}