#include <iostream>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version) {
    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                if (mid - 1 >= 1 && !isBadVersion(mid - 1)) return mid;
                high = mid - 1;
            } else {
                if (mid + 1 <= n && isBadVersion(mid + 1)) return mid + 1;
                low = mid + 1;
            }
        }
        return mid;
    }
};

int main(int argc, char **argv) {
    // test
    return 0;
}