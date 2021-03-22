#include <iostream>
#include <vector>

using std::vector;

class NumArray {
    int *answer = nullptr;
public:
    NumArray(vector<int>& nums) {
        int sz = nums.size();
        answer = new int[sz];
        answer[0] = nums[0];
        for (int i = 1; i < sz; i++) {
            answer[i] = answer[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return answer[j];
        return answer[j] - answer[i - 1];
    }

    ~NumArray() {
        delete [] answer;
    }
};

int main(int argc, char **argv) {
    vector<int> vec{1, 2, 3, 4, 5};
    NumArray obj(vec);

    int ret = obj.sumRange(2, 4);
    std::cout << "sumRange(2, 4) = " << ret << std::endl;
    return 0;
}