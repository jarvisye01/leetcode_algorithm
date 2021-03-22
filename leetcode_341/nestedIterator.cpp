#include <iostream>
#include <vector>

using std::vector;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    vector<int> vec;
    int idx;
    void iterate_helper(NestedInteger & nestedNum, vector<int>& vec) {
        if (nestedNum.isInteger()) {
            vec.push_back(nestedNum.getInteger());
            return;
        }

        auto list = nestedNum.getList();
        for (auto x: list)
            iterate_helper(x, vec);
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto x: nestedList)
            iterate_helper(x, vec);
        idx = 0;
    }
    
    int next() {
        return vec[idx++]; 
    }
    
    bool hasNext() {
        return idx < vec.size();
    }
};

int main(int argc, char **argv) {
    return 0;
}