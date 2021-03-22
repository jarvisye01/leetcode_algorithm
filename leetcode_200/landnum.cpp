#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

struct point {
    int x, y;
    point(int xx, int yy): x(xx), y(yy) {}
    bool operator== (const point& p) const {
        return x == p.x && y == p.y;
    }
};

struct Hash {
    size_t operator() (const point& p) const {
        return (p.x + p.y) + (p.x * p.y);
    }
};

class Solution {
    void calculate_aux(vector<vector<char>>& grid, int x, int y, int M, int N, unordered_set<point, Hash>& info) {
        // std::cout << "x = " << x << ", y = " << y << std::endl;
        info.insert(point(x, y));
        if (x - 1 >= 0 && info.find(point(x - 1, y)) == info.end() && grid[x - 1][y] == '1')
            calculate_aux(grid,  x - 1, y, M, N, info);
        if (y - 1 >= 0 && info.find(point(x, y - 1)) == info.end() && grid[x][y - 1] == '1')
            calculate_aux(grid,  x, y - 1, M, N, info);
        if (x + 1 < M && info.find(point(x + 1, y)) == info.end() && grid[x + 1][y] == '1') 
            calculate_aux(grid, x + 1, y, M, N, info);
        if (y + 1 < N && info.find(point(x, y + 1)) == info.end() && grid[x][y + 1] == '1') 
            calculate_aux(grid, x, y + 1, M, N, info);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int M, N;
        if ((M = grid.size()) == 0) 
            return 0;
        if ((N = grid[0].size()) == 0)
            return 0;

        unordered_set<point, Hash> info;
        int ret = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '0' || info.find(point(i, j)) != info.end()) 
                    continue;
                // std::cout << "i = " << i << ", j = " << j << std::endl;
                ret++;
                calculate_aux(grid, i, j, M, N, info);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'}, 
        {'1', '1', '0', '1', '0'}, 
        {'1', '1', '0', '0', '0'}, 
        {'0', '0', '0', '0', '0'}
        // {'1', '1', '1', '1', '1'},
        // {'1', '0', '0', '0', '1'},
        // {'1', '0', '1', '0', '1'},
        // {'1', '0', '0', '0', '1'},
        // {'1', '1', '1', '1', '1'}
    };
    int ret = s.numIslands(grid);
    std::cout << ret << std::endl;
    return 0;
}