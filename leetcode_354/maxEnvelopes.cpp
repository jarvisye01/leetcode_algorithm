#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using std::vector;
using std::set;
using std::queue;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int sz = envelopes.size();
        if (sz == 0) return 0;

        vector<set<int>> in(sz, set<int>());
        vector<set<int>> out(sz, set<int>());

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (i == j) continue;
                if (envelopes[i][0] < envelopes[j][0] && envelopes[i][1] < envelopes[j][1]) {
                    in[j].insert(i);
                    out[i].insert(j);
                } else if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    in[i].insert(j);
                    out[j].insert(i);
                }
            }
        }

        vector<int> dp(sz, 0);
        vector<int> mark(sz, 0);
        vector<set<int>> count(sz, set<int>()); 
        int vis = 0;

        while (vis < sz) {
            for (int i = 0; i < sz; i++) {
                if (!mark[i] && count[i].size() == in[i].size()) {
                    int tm = 0;
                    for (int x: in[i]) {
                        tm = std::max(tm, dp[x]);
                    }

                    for (int x: out[i]) {
                        count[x].insert(i);
                    }

                    mark[i] = 1;
                    dp[i] = tm + 1;
                    vis++;
                }
            }
        }

        auto iter = std::max_element(dp.begin(), dp.end());
        return iter != dp.end() ? *iter : 0;
    }

    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;

        int dp[sz + 1], len = 1;
        dp[len] = nums[0];

        for (int i = 1; i < sz; i++) {
            if (nums[i] > dp[len]) 
                dp[++len] = nums[i];
            else {
                int l = 1, h = len, pos = 0;
                while (l <= h) {
                    int mid = l + (h - l) / 2;
                    if (dp[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else 
                        h = mid - 1;
                }
                dp[pos + 1] = nums[i];
            }
        }

        return len;
    }

    int maxEnvelopesII(vector<vector<int>>& envelopes) {
        int sz = envelopes.size();
        if (sz == 0) return 0;

        std::sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2) -> bool {
            if (v1[0] == v2[0]) 
                return v2[1] < v1[1];
            return v1[0] < v2[0];
        });

        vector<int> nums(sz);
        for (int i = 0; i < sz; i++) {
            nums[i] = envelopes[i][1];
        }

        return lengthOfLIS(nums);
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    Solution s;
    std::cout << "maxEnvelopes = " << s.maxEnvelopes(envelopes) << std::endl;
    std::cout << "maxEnvelopesII = " << s.maxEnvelopesII(envelopes) << std::endl;
    return 0;
}