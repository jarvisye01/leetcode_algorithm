#include <iostream>
#include <vector>

using std::vector;

class NumMatrix {
    int **arr = nullptr;
    int M = 0, N = 0;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if ((M = matrix.size()) == 0) return;
        if ((N = matrix[0].size()) == 0) return;

        arr = new int*[M];
        for (int i = 0; i < M; i++) arr[i] = new int[N];

        arr[0][0] = matrix[0][0];
        for (int i = 1; i < M; i++) arr[i][0] = arr[i - 1][0] + matrix[i][0];
        for (int j = 1; j < N; j++) arr[0][j] = arr[0][j - 1] + matrix[0][j];

        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || col1 < 0 || row1 >= M || col1 >= N ||
            row2 < 0 || col2 < 0 || row2 >= M || col2 >= N) return 0;

        if (row1 == 0 && col1 == 0) return arr[row2][col2];
        else if (row1 == 0) return arr[row2][col2] - arr[row2][col1 - 1];
        else if (col1 == 0) return arr[row2][col2] - arr[row1 - 1][col2];
        return arr[row2][col2] - arr[row2][col1 - 1] - arr[row1 - 1][col2] + arr[row1 - 1][col1 - 1];
    }

    ~NumMatrix() {
        for (int i = 0; i < M; i++) 
            delete [] arr[i];

        delete [] arr;
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix nm(matrix);
    std::cout << nm.sumRegion(1, 1, 3, 4) << std::endl;
    std::cout << nm.sumRegion(2, 1, 4, 3) << std::endl;
    std::cout << nm.sumRegion(1, 1, 2, 2) << std::endl;
    std::cout << nm.sumRegion(1, 2, 2, 4) << std::endl;
    return 0;
}