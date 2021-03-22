#include <iostream>
#include <vector>

using std::vector;

class Solution {
    int getSideLives(const vector<vector<int>>& arr, int i, int j, int M, int N) {
        int ret = 0;
        if (j - 1 >= 0 && (arr[i][j - 1] == 1 || arr[i][j - 1] == 2)) ret++;
        if (j - 1 >= 0 && i - 1 >= 0 && (arr[i - 1][j - 1] == 1 || arr[i - 1][j - 1] == 2)) ret++;
        if (i - 1 >= 0 && (arr[i - 1][j] == 1 || arr[i - 1][j] == 2)) ret++;
        if (i - 1 >= 0 && j + 1 < N && (arr[i - 1][j + 1] == 1 || arr[i - 1][j + 1] == 2)) ret++;
        if (j + 1 < N && (arr[i][j + 1] == 1 || arr[i][j + 1] == 2)) ret++;
        if (i + 1 < M && j + 1 < N && (arr[i + 1][j + 1] == 1 || arr[i + 1][j + 1] == 2)) ret++;
        if (i + 1 < M && (arr[i + 1][j] == 1 || arr[i + 1][j] == 2)) ret++;
        if (i + 1 < M && j - 1 >= 0 && (arr[i + 1][j - 1] == 1 || arr[i + 1][j - 1] == 2)) ret++;
        return ret;
    }
public:
    // 0 => dead 
    // 1 => live
    // 2 => new dead
    // 3 => new live
    void gameOfLife(vector<vector<int>>& board) {
        int M, N;
        if ((M = board.size()) == 0) return;
        if ((N = board[0].size()) == 0) return;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)  {    
                int liveNum = getSideLives(board, i, j, M, N);
                if (board[i][j] == 0) {
                    if (liveNum == 3) board[i][j] = 3;
                } else {
                    if (liveNum < 2 || liveNum > 3) board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)  {
                if (board[i][j] == 2) board[i][j] = 0;
                else if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> test = {
        {0, 1, 0}, 
        {0, 0, 1}, 
        {1, 1, 1}, 
        {0, 0, 0}
    };
    Solution s;
    s.gameOfLife(test);
    for (int i = 0; i < test.size(); i++) {
        for (int j = 0; j < test[0].size(); j++)  {
            std::cout << test[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}