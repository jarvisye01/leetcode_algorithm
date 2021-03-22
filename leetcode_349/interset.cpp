#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for (int x: nums1) 
            set1.insert(x);
        for (int x: nums2) 
            set2.insert(x);

        vector<int> ret;
        for (int e: set1) {
            if (set2.find(e) != set2.end()) 
                ret.push_back(e);
        }

        return ret;
    }
};

int main(int agrc, char **argv) {
    Solution s;
    vector<int> vec1{1, 2, 2, 1};
    vector<int> vec2{2, 3, 4};
    vector<int> ret = s.intersection(vec1, vec2);
    for (int x: ret) 
        std::cout << x << "";
    std::cout << std::endl;
    return 0;
}