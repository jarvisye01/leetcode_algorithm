#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

struct hasher {
    size_t operator() (const std::pair<int, int>& p) const {
        return p.first * p.second + p.first + p.first;
    }
};

class Solution {
    void findWordAux(vector<vector<char>>& board, int i, int j, int idx, const string& s, bool& ret, unordered_set<std::pair<int, int>, hasher>& set) {
        if (idx == s.length()) 
            ret = true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] != s[idx]) {
            return;
        }

        set.insert(std::make_pair(i, j));
        if (set.find(std::make_pair(i + 1, j)) == set.end()) 
            findWordAux(board, i + 1, j, idx + 1, s, ret, set);
        if (set.find(std::make_pair(i, j + 1)) == set.end()) 
            findWordAux(board, i, j + 1, idx + 1, s, ret, set);
        if (set.find(std::make_pair(i - 1, j)) == set.end())
            findWordAux(board, i - 1, j, idx + 1, s, ret, set);
        if (set.find(std::make_pair(i, j - 1)) == set.end())
            findWordAux(board, i, j - 1, idx + 1, s, ret, set);

        set.erase(std::make_pair(i, j));   
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int M, N;
        vector<string> results;
        if ((M = board.size()) == 0 || (N = board[0].size()) == 0) return results;

        for (string& s: words) {
            bool ret = false;
            if (s.length() == 0)
                continue;
            
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == s[0]) {
                        unordered_set<std::pair<int, int>, hasher> set;
                        findWordAux(board, i, j, 0, s, ret, set);
                    }
                }
                if (ret) {
                    results.push_back(s);
                    break;
                }
            }
        }

        return results;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    // vector<vector<char>> board = {{'a', 'a'}};
    // vector<string> words = {"aaa"};

    vector<string> ret = s.findWords(board, words);
    for (string& str: ret) 
        std::cout << str << " ";
    std::cout << std::endl;
    return 0;
}