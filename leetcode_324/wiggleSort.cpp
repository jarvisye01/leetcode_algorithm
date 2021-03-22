#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz, mid;
        if ((sz = nums.size()) == 0 || sz == 1) return;
        mid = sz / 2;
        int *arr = new int[sz];

        std::sort(nums.begin(), nums.end());

        int a = 0, b = 0, m = -1, key = -1, s = -1;
        while (b < sz) {
            while (b < sz && nums[b] == nums[a]) { b++; }
            if (b - a > m) {
                m = b - a;
                s = a;
                key = nums[a];
            }
            a = b;
        }

        if (sz % 2 == 0 && m == sz / 2 && nums[0] != key && nums[sz - 1] != key) {
            int ii = 0, c = s + m;
            while (c < sz) {
                arr[ii++] = key;
                arr[ii++] = nums[c++];
            }

            c %= sz;

            while (c < s) {
                arr[ii++] = nums[c++];
                arr[ii++] = key;
            }
        } else {
            int i = 0, j, idx = 0;
            j = sz % 2 == 0 ? mid : mid + 1;

            while (i < mid && j < sz) {
                arr[idx++] = nums[i++];
                arr[idx++] = nums[j++];
            }

            if (sz % 2 != 0) arr[idx] = nums[mid];
        }

        for (int i = 0; i < sz; i++) nums[i] = arr[i];

        delete [] arr;
    }
};

int main(int argc, char **argv) {
    vector<int> vec{4, 5, 5, 5, 5, 6, 6, 6};
    Solution s;
    s.wiggleSort(vec);

    for (int x: vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}