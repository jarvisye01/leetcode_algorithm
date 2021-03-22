#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using std::vector;
using std::stack;
using std::priority_queue;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz;
        if ((sz = nums.size()) < 3) 
            return false;

        stack<int> s;
        priority_queue<int, vector<int>, std::greater<typename vector<int>::value_type>> pq;
        for (int i = 0; i < sz; i++) {
            while (s.size() != 0 && s.top() >= nums[i])
                s.pop();
            s.push(nums[i]);

            if (s.size() == 2)
                pq.push(s.top());
            if (s.size() >= 3 || (pq.size() > 0 && nums[i] > pq.top())) 
                return true;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    vector<int> nums{20, 100, 10, 12, 5, 13};
    Solution s;
    std::cout << (s.increasingTriplet(nums) ? "true" : "false") << std::endl;
    return 0;
}