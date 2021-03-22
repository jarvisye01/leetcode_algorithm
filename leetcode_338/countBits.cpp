#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        
        ret.push_back(0);   // 0
        
        for (int i = 1; i <= num; i++) 
            ret.push_back(ret[i / 2] + i % 2);
        
        return ret;
    }
};

template<class T>
void printVec(const vector<T>& vec) {
    for (T t: vec) 
        std::cout << t << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    Solution s;
    for (int i = 0; i < 20; i++) 
        printVec(s.countBits(i));
    return 0;
}