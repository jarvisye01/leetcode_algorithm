#include <iostream>
#include <vector>

using std::vector;

class Solution {
    void swap(vector<int>& arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
public:
    int missingNumber(vector<int>& nums) {
        int k = 0;
        int sz = nums.size(), temp = -1, ret = -1;
        for (int i = 0; i < sz; i++) {
            while (nums[i] != i) {
                if (nums[i] == sz) {
                    temp = nums[i];
                    nums[i] = -1;
                    ret = i;
                    break;
                }
                if (nums[nums[i]] == -1) {
                    nums[nums[i]] = nums[i];
                    nums[i] = -1;
                    ret = i;
                    break;
                }
                swap(nums, i, nums[i]);
            }
        }

        if (temp == -1) return sz;
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> vec{9, 6, 4, 2, 3, 5, 7, 0, 1};
    // vector<int> vec{0, 1};
    int ret = s.missingNumber(vec);
    std::cout << "missing number: " << ret << std::endl;
    return 0;
}