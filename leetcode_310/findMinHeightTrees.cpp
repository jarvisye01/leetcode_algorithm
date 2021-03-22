#include <iostream>
#include <vector>
#include <set>
#include <queue>

using std::vector;
using std::queue;
using std::set;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> ret;
    vector<set<int>> g(n);
    vector<int> degree(n, 0);
    queue<int> q;

    // one node
    if (n == 1)
    {
      ret.push_back(0);
      return ret;
    }

    // to graph
    for (auto& vec: edges)
    {
      g[vec[0]].insert(vec[1]);
      g[vec[1]].insert(vec[0]);
      degree[vec[0]]++;
      degree[vec[1]]++;
    }

    // add leaf nodes
    for (int i = 0; i < n; i++)
      if (degree[i] == 1)
        q.push(i);

    while (q.size() > 0)
    {
      ret.clear();
      int tsz = q.size();
      for (int i = 0; i < tsz; i++)
      {
        int node = q.front();
        q.pop();
        ret.push_back(node);
        for (int x: g[node])
        {
          degree[x]--;
          if (degree[x] == 1)
            q.push(x);
        }
      }  
    }

    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  int n = 5000;
  vector<vector<int>> edges;
  for (int i = 0; i < 4999; i++)
    edges.push_back({i, i + 1});
  auto ret = s.findMinHeightTrees(n, edges);
  for (int x: ret)
    std::cout << x << " ";
  std::cout << std::endl;
  return 0;
}