#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::vector;

class Solution {
    vector<int> initNums;
    vector<int> curNums;
    int N;

    int rand(int n) {
        return std::rand() % n;
    }
public:
    Solution(vector<int>& nums)
    : initNums(nums), curNums(nums), N(nums.size()) { 
        // srand
        std::srand(std::time(nullptr));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        curNums = initNums;
        return curNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < N; i++) {
            int t = rand(N - i);
            std::swap(curNums[i], curNums[i + t]);
        }
        return curNums;
    }
};

int main(int argc, char **argv) {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution s(nums);

    for (int i = 0; i < 10; i++) {
        auto v1 = s.reset();
        std::cout << "before: ";
        for (int x: v1) 
            std::cout << x << " ";
        std::cout << std::endl;

        auto v2 = s.shuffle();
        std::cout << "shuffle: ";
        for (int x: v2) 
            std::cout << x << " ";
        std::cout << std::endl;
    }
    return 0;
}