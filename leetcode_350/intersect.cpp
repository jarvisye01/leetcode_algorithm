#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size(), i = 0, j = 0;
        vector<int> ret;
        if (sz1 == 0 || sz2 == 0) return ret;

        // sort
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        // two pointers
        while (i < sz1 && j < sz2) {
            if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                i++, j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return ret;
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    auto ret = s.intersect(nums1, nums2);
    for (int x: ret) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}