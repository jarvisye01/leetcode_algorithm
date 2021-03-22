#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M, N;
        if ((M = matrix.size()) == 0) return false;
        if ((N = matrix[0].size()) == 0) return false;

        int i = 0, j = N - 1;
        while (i < M && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else i++; 
        }
        return false;
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> vec = {
        {1,4,7,11,15}, 
        {2,5,8,12,19}, 
        {3,6,9,16,22}, 
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    Solution s;
    std::cout << "result: " << s.searchMatrix(vec, 9) << std::endl;
    return 0;
}