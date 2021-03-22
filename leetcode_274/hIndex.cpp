#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0, sz;
        if ((sz = citations.size()) == 0) return h;
        std::sort(citations.begin(), citations.end());

        int i = sz - 1;
        while (i >= 0) {
            if (citations[i] >= sz - i) h = sz - i;
            else break;
            i--;
        }

        return h;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> citations = {3, 0, 6, 1, 5};
    int ret = s.hIndex(citations);
    std::cout << "hIndex: " << ret << std::endl;
    return 0;
}