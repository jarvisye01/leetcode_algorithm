#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0, sz;
        if ((sz = citations.size()) == 0) return h;

        int low = 0, high = sz - 1, mid = low + (high - low) / 2;

        while (mid >= low && mid <= high) {
            if (citations[mid] >= sz - mid) {
                h = std::max(h, sz - mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            mid = low + (high - low) / 2;
        }
        return h;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> citations = {0, 1, 3, 5, 6};
    int ret = s.hIndex(citations);
    std::cout << "hIndex: " << ret << std::endl;
    return 0;
}